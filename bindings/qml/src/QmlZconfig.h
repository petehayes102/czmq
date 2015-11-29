/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_ZCONFIG_H
#define QML_ZCONFIG_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZconfig : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)
    
public:
    zconfig_t *self;
    
    QmlZconfig() { self = NULL; }
    bool isNULL() { return self == NULL; }
    
    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZconfig.cpp
    
public slots:
    //  Return name of config item
    QString name ();

    //  Return value of config item
    QString value ();

    //  Insert or update configuration key with value
    void put (const QString &path, const QString &value);

    //  Equivalent to zconfig_put, accepting a format specifier and variable
    //  argument list, instead of a single string value.                    
    void putf (const QString &path, const QString &format);

    //  Get value for config item into a string value; leading slash is optional
    //  and ignored.                                                            
    QString get (const QString &path, const QString &defaultValue);

    //  Set config item name, name may be NULL
    void setName (const QString &name);

    //  Set new value for config item. The new value may be a string, a printf  
    //  format, or NULL. Note that if string may possibly contain '%', or if it 
    //  comes from an insecure source, you must use '%s' as the format, followed
    //  by the string.                                                          
    void setValue (const QString &format);

    //  Find our first child, if any
    QmlZconfig *child ();

    //  Find our first sibling, if any
    QmlZconfig *next ();

    //  Find a config item along a path; leading slash is optional and ignored.
    QmlZconfig *locate (const QString &path);

    //  Locate the last config item at a specified depth
    QmlZconfig *atDepth (int level);

    //  Execute a callback for each config item in the tree; returns zero if
    //  successful, else -1.                                                
    int execute (zconfig_fct handler, void *arg);

    //  Add comment to config item before saving to disk. You can add as many
    //  comment lines as you like. If you use a null format, all comments are
    //  deleted.                                                             
    void setComment (const QString &format);

    //  Return comments of config item, as zlist.
    QmlZlist *comments ();

    //  Save a config tree to a specified ZPL text file, where a filename
    //  "-" means dump to standard output.                               
    int save (const QString &filename);

    //  Equivalent to zconfig_save, taking a format string instead of a fixed
    //  filename.                                                            
    int savef (const QString &format);

    //  Report filename used during zconfig_load, or NULL if none
    const QString filename ();

    //  Save a config tree to a new memory chunk
    zchunk_t *chunkSave ();

    //  Save a config tree to a new null terminated string
    QString strSave ();

    //  Return true if a configuration tree was loaded from a file and that
    //  file has changed in since the tree was loaded.                     
    bool hasChanged ();

    //  Print the config file to open stream
    void fprint (FILE *file);

    //  Print properties of object
    void print ();
};

class QmlZconfigAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;
    
public:
    QmlZconfigAttached (QObject* attached) {
        Q_UNUSED (attached);
    };
    
public slots:
    //  Load a config tree from a specified ZPL text file; returns a zconfig_t  
    //  reference for the root, if the file exists and is readable. Returns NULL
    //  if the file does not exist.                                             
    QmlZconfig *load (const QString &filename);

    //  Equivalent to zconfig_load, taking a format string instead of a fixed
    //  filename.                                                            
    QmlZconfig *loadf (const QString &format);

    //  Reload config tree from same file that it was previously loaded from.
    //  Returns 0 if OK, -1 if there was an error (and then does not change  
    //  existing data).                                                      
    int reload (QmlZconfig *selfP);

    //  Load a config tree from a memory chunk
    QmlZconfig *chunkLoad (zchunk_t *chunk);

    //  Load a config tree from a null-terminated string
    QmlZconfig *strLoad (const QString &string);

    //  Self test of this class
    void test (bool verbose);

    //  Create new config item
    QmlZconfig *construct (const QString &name, QmlZconfig *parent);

    //  Destroy a config item and all its children
    void destruct (QmlZconfig *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZconfig, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
