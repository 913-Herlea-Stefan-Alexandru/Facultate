/****************************************************************************
** Meta object code from reading C++ file 'GenesGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Lecture_9/genes/GenesGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GenesGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GenesGUI_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenesGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenesGUI_t qt_meta_stringdata_GenesGUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GenesGUI"
QT_MOC_LITERAL(1, 9, 18), // "genesUpdatedSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "addGeneSignal"
QT_MOC_LITERAL(4, 43, 11), // "std::string"
QT_MOC_LITERAL(5, 55, 8), // "geneName"
QT_MOC_LITERAL(6, 64, 12), // "organismName"
QT_MOC_LITERAL(7, 77, 8), // "sequence"
QT_MOC_LITERAL(8, 86, 7) // "addGene"

    },
    "GenesGUI\0genesUpdatedSignal\0\0addGeneSignal\0"
    "std::string\0geneName\0organismName\0"
    "sequence\0addGene"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenesGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    3,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    5,    6,    7,

       0        // eod
};

void GenesGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GenesGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->genesUpdatedSignal(); break;
        case 1: _t->addGeneSignal((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        case 2: _t->addGene((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GenesGUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenesGUI::genesUpdatedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GenesGUI::*)(const std::string & , const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenesGUI::addGeneSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GenesGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GenesGUI.data,
    qt_meta_data_GenesGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GenesGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenesGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GenesGUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GenesGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void GenesGUI::genesUpdatedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GenesGUI::addGeneSignal(const std::string & _t1, const std::string & _t2, const std::string & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
