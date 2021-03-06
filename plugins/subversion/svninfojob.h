/***************************************************************************
 *   This file is part of KDevelop                                         *
 *   Copyright 2007 Andreas Pakulat <apaku@gmx.de>                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef KDEVPLATFORM_PLUGIN_SVNINFOJOB_H
#define KDEVPLATFORM_PLUGIN_SVNINFOJOB_H

#include "svnjobbase.h"

#include <QDateTime>
#include <QUrl>

#include <vcs/vcsrevision.h>

class SvnInternalInfoJob;


/// A structure which describes various system-generated metadata about
/// a working-copy path or URL.
class SvnInfoHolder
{
public:
    QString name;
    QUrl url;
    qlonglong rev;
    int kind;
    QUrl repoUrl;
    QString repouuid;
    qlonglong lastChangedRev;
    QDateTime lastChangedDate;
    QString lastChangedAuthor;
    int scheduled;
    QUrl copyFromUrl;
    qlonglong copyFromRevision;
    QDateTime textTime;
    QDateTime propertyTime;
    QString oldFileConflict;
    QString newFileConflict;
    QString workingCopyFileConflict;
    QString propertyRejectFile;

};


/// This is an svn internal class, it shouldn't be used outside of the svn
/// plugin
class SvnInfoJob : public SvnJobBaseImpl<SvnInternalInfoJob>
{
    Q_OBJECT
public:
    enum ProvideInformationType
    {
        AllInfo,
        RevisionOnly,
        RepoUrlOnly
    };
    explicit SvnInfoJob( KDevSvnPlugin* parent );
    QVariant fetchResults() override;
    void start() override;
    void setLocation( const QUrl &location );
    void setProvideInformation( ProvideInformationType );
    void setProvideRevisionType( KDevelop::VcsRevision::RevisionType );
public Q_SLOTS:
    void setInfo( const SvnInfoHolder& );
private:
    SvnInfoHolder m_info;
    ProvideInformationType m_provideInfo;
    KDevelop::VcsRevision::RevisionType m_provideRevisionType;

};

Q_DECLARE_METATYPE( SvnInfoHolder )

#endif

