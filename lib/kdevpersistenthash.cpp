/* This file is part of KDevelop
Copyright (C) 2006 Adam Treat <treat@kde.org>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.
*/

#include "kdevpersistenthash.h"

#include <iostream>
#include <fstream>

#include <QFile>
#include <QDataStream>
#include <QReadLocker>
#include <QWriteLocker>

#include "kdevast.h"
#include "kdevcore.h"
#include "kdevlanguagesupport.h"

KDevPersistentHash::KDevPersistentHash( QObject *parent )
        : QObject( parent )
{
#ifndef NO_GOOGLE_SPARSEHASH
    m_astHash.set_deleted_key( NULL );
#endif
}

KDevPersistentHash::~KDevPersistentHash()
{
#ifndef NO_GOOGLE_SPARSEHASH
#else
    QHashIterator<KUrl, KDevAST*> it = m_astHash;
    while (it.hasNext()) {
        it.next();
        it.value()->release();
    }
#endif
}

void KDevPersistentHash::insertAST( const KUrl &url, KDevAST *ast )
{
    QWriteLocker lock(&m_mutex);

#ifndef NO_GOOGLE_SPARSEHASH
    m_astHash[ url.url() ] = ast;
#else
    if (m_astHash.contains(url)) {
        m_astHash[url]->release();
        for (QMultiHash<QString, KDevAST*>::Iterator it = m_filenameAstHash.find(url.fileName()); it != m_filenameAstHash.end() && it.key() == url.fileName(); ++it)
            if (it.value() == ast) {
                m_filenameAstHash.erase(it);
                break;
            }
    }

    m_astHash.insert(url, ast);
    m_filenameAstHash.insert(url.fileName(), ast);
#endif
}

KDevAST * KDevPersistentHash::retrieveAST(const KUrl & url)
{
    QReadLocker lock(&m_mutex);

#ifndef NO_GOOGLE_SPARSEHASH
    return m_astHash[ url.url() ];
#else
    if (m_astHash.contains(url))
        return m_astHash[ url ];
    return 0;
#endif
}

void KDevPersistentHash::clearASTs(KDevLanguageSupport* language)
{
#ifndef NO_GOOGLE_SPARSEHASH
#else
    QMutableHashIterator<KUrl, KDevAST*> it = m_astHash;
    while (it.hasNext()) {
        it.next();
        if (it.value()->language == language) {
            it.value()->release();
            it.remove();
        }
    }
#endif
}

KDevAST* KDevPersistentHash::retrieveAST( const QString &filename )
{
    QReadLocker lock(&m_mutex);

#ifndef NO_GOOGLE_SPARSEHASH
    return m_astHash[ url.url() ];
#else
    if (m_filenameAstHash.contains(filename))
        return m_filenameAstHash.values(filename).first();

    return 0;
#endif
}

void KDevPersistentHash::load()
{
    QWriteLocker lock(&m_mutex);

#ifndef NO_GOOGLE_SPARSEHASH
    kDebug() << k_funcinfo << endl;
    QString fileName = "/home/kde/trunk/KDE/kdevelop/.kdev4/pcstest";
    FILE *f = fopen( fileName.toLatin1().data(), "r" );
    if ( f )
    {
        m_astHash.read_metadata( f );
    }

    fpos_t pos;
    if ( fgetpos( f, &pos ) )
    {
        kDebug() << "WARNING couldn't skip metadata!! ABORT" << endl;
        return;
    }

    QFile file;
    if ( file.open( f, QIODevice::ReadOnly ) )
    {
        file.seek( pos.__pos );

        QDataStream in( &file );

        PHASH::iterator it = m_astHash.begin();
        for ( ; it != m_astHash.end(); ++it )
        {
            QString str;
            qint32 ast;
            in >> str >> ast;
            new (const_cast<QString*>(&it->first)) QString(str);
            new (&it->second) int(ast);
        }

        file.close();
    }

    PHASH::iterator it = m_astHash.begin();
    for ( ; it != m_astHash.end(); ++it )
    {
        kDebug() << "key = " << it->first << " value = " << it->second << endl;
    }
#endif
}

void KDevPersistentHash::save()
{
    QReadLocker lock(&m_mutex);

#ifndef NO_GOOGLE_SPARSEHASH
    kDebug() << k_funcinfo << endl;
    QString fileName = "/home/kde/trunk/KDE/kdevelop/.kdev4/pcstest";
    FILE *f = fopen( fileName.toLatin1().data(), "w" );
    if ( f )
    {
        m_astHash.write_metadata( f );
    }
    fclose(f);

    std::ofstream out( fileName.toLatin1().data(), std::ios::binary | std::ios::app );
    if (out.is_open())
    {
        PHASH::iterator it = m_astHash.begin();
        for ( ; it != m_astHash.end(); ++it )
        {
            char *s = it->first.toLatin1().data();
            out.write( reinterpret_cast<char*>(s), sizeof(s) );
            KDevCore::activeLanguage()->write( it->second, out );
        }

        out.flush();
        out.close();
    }
#endif
}

#include "kdevpersistenthash.moc"

// kate: space-indent on; indent-width 4; tab-width 4; replace-tabs on
