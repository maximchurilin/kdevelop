/***************************************************************************
 *   Copyright (C) 1999-2001 by Bernd Gehrmann                             *
 *   bernd@kdevelop.org                                                    *
 *   Copyright (C) 2003 by Mario Scalas                                    *
 *   mario.scalas@libero.it                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _CVSPART_H_
#define _CVSPART_H_

#include <qguardedptr.h>

#include "kdevversioncontrol.h"

class Context;
class QPopupMenu;
class KDialogBase;
class KURL;
class KURL::List;
class KAction;
class CvsWidget;
class CvsForm;
class KProcess;
class CvsPart;


class CvsPart : public KDevVersionControl
{
    Q_OBJECT

public:
    //! Available Cvs operations
    enum CvsOperation { opAdd, opCommit, opUpdate, opRevert, opRemove, opLog, opDiff, opTag };

    //! Standard constructor.
    CvsPart( QObject *parent, const char *name, const QStringList & );
    //! Destructor.
    ~CvsPart();

    /**
    * Returns the configuration widget (for properly configuring the project to
    * use CVS), child of @p parent.
    */
    virtual QWidget *newProjectWidget( QWidget *parent );
    /**
    * Setup a directory tree for use with CVS.
    */
    virtual void createNewProject( const QString& dir );

private slots:
    //! Add menu items binded to cvs operations' slots to @p popup, using
    //! data in @p context.
    //! Not that @p context _must_ be FileContext-type, otherwise will do
    //! nothing.
    void contextMenu( QPopupMenu *popup, const Context *context );

    // Cvs operations (menubar)
    void slotActionCommit();
    void slotActionUpdate();
    void slotActionAdd();
    void slotActionRemove();
    void slotActionRevert();
    void slotActionLog();
    void slotActionDiff();
    void slotActionTag();
    void slotActionAddToIgnoreList();
    void slotActionRemoveFromIgnoreList();

    // Cvs operations (context menu)
    void slotCommit();
    void slotUpdate();
    void slotAdd();
    void slotRemove();
    void slotRevert();
    void slotLog();
    void slotDiff();
    void slotTag();
    void slotAddToIgnoreList();
    void slotRemoveFromIgnoreList();

    void slotProjectOpened();
    void slotProjectClosed();

    void slotAddFilesToProject(const QStringList &);
    void slotRemovedFilesFromProject(const QStringList &);

    //! Display "cvs diff" results in the diff part (embedded views).
    void slotDiffFinished();
    void receivedStdout( KProcess*, char*, int );
    void receivedStderr( KProcess*, char*, int );

    //! Adds a configuration widget (for properly configuring CVS command-line options)
    //! and adds it to @p dlg.
    void projectConfigWidget( KDialogBase *dlg );

    //! Called when the user wishes to stop an operation.
    void slotStopButtonClicked( KDevPlugin* );

    //! Creates a working copy from remote repository
    void slotCheckOut();


private:
    // Implementation of CvsOperations
    void commit( const KURL::List& urlList );
    void update( const KURL::List& urlList );
    void add( const KURL::List& urlList );
    void remove( const KURL::List& urlList );
    void revert( const KURL::List& urlList );
    void log( const KURL::List& urlList );
    void diff( const KURL::List& urlList );
    void tag( const KURL::List& urlList );
    void addToIgnoreList( const KURL::List& urlList );
    void removeFromIgnoreList( const KURL::List& urlList );

    //! This implements commit operation: it is reused in several parts.
    QString buildCommitCmd( const QString _directoryName, const QStringList &paths, const QString _logMessage );

    void init();

    //! Setup actions.
    void setupActions();
    //! Returns the KURL for the currently focused document, if there is any
    bool urlFocusedDocument( KURL &url );
    //! Call this every time a slot for cvs operations starts!! (It will setup the
    //! state (file/dir URL, ...).
    //! It will also display proper error messages so the caller must only exit if
    //! it fails (return false); if return true than basic requisites for cvs operation
    //! are satisfied.
    bool prepareOperation( CvsOperation op );
    //! Call this every time a slot for cvs operations ends!! (It will restore the state for a new
    //! operation).
    void doneOperation();

    //! The value for overriding the $CVS_RSH env variable
    QString cvs_rsh() const;

    //! A list of KURLs of the files to be "operated" on (to be committed, added, removed, ...)
    KURL::List urls;

    //! Reference to widget integrated in the "bottom tabbar" (IDEAL)
    QGuardedPtr<CvsWidget> m_widget;
    //! This is a pointer to the d->form used for collecting data about CVS project creation (used
    //! by the ApplicationWizard in example)
    QGuardedPtr<CvsForm> m_cvsConfigurationForm;

    //! Shell process reference (i.e. used by 'cvs diff')
    KProcess* proc;
    //! Buffers for process' standard output and error
    QString stdOut, stdErr;

    //! Actions
    KAction *actionCommit,
        *actionDiff,
        *actionLog,
        *actionAdd,
        *actionRemove,
        *actionUpdate,
        *actionRevert,
        *actionTag,
        *actionAddToIgnoreList,
        *actionRemoveFromIgnoreList;
};

#endif
