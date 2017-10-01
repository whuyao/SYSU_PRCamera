/****************************************************************************
** Meta object code from reading C++ file 'loadsvmdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SYSU_PRCamera/loadsvmdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadsvmdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoadSVMDlg_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoadSVMDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoadSVMDlg_t qt_meta_stringdata_LoadSVMDlg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LoadSVMDlg"
QT_MOC_LITERAL(1, 11, 11), // "sig_message"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "smsg"
QT_MOC_LITERAL(4, 29, 15), // "loadClassifiers"
QT_MOC_LITERAL(5, 45, 11) // "openSVMFile"

    },
    "LoadSVMDlg\0sig_message\0\0smsg\0"
    "loadClassifiers\0openSVMFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoadSVMDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoadSVMDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoadSVMDlg *_t = static_cast<LoadSVMDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loadClassifiers(); break;
        case 2: _t->openSVMFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoadSVMDlg::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoadSVMDlg::sig_message)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LoadSVMDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LoadSVMDlg.data,
      qt_meta_data_LoadSVMDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoadSVMDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoadSVMDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoadSVMDlg.stringdata0))
        return static_cast<void*>(const_cast< LoadSVMDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int LoadSVMDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LoadSVMDlg::sig_message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
