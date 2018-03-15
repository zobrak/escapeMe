/****************************************************************************
** Meta object code from reading C++ file 'pincode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../escapeMe/pincode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pincode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PinCode_t {
    QByteArrayData data[14];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PinCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PinCode_t qt_meta_stringdata_PinCode = {
    {
QT_MOC_LITERAL(0, 0, 7), // "PinCode"
QT_MOC_LITERAL(1, 8, 15), // "on_retr_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "on_num1_clicked"
QT_MOC_LITERAL(4, 41, 15), // "on_num2_clicked"
QT_MOC_LITERAL(5, 57, 15), // "on_num3_clicked"
QT_MOC_LITERAL(6, 73, 15), // "on_num4_clicked"
QT_MOC_LITERAL(7, 89, 15), // "on_num5_clicked"
QT_MOC_LITERAL(8, 105, 15), // "on_num6_clicked"
QT_MOC_LITERAL(9, 121, 15), // "on_num7_clicked"
QT_MOC_LITERAL(10, 137, 15), // "on_num8_clicked"
QT_MOC_LITERAL(11, 153, 15), // "on_num9_clicked"
QT_MOC_LITERAL(12, 169, 15), // "on_num0_clicked"
QT_MOC_LITERAL(13, 185, 7) // "valider"

    },
    "PinCode\0on_retr_clicked\0\0on_num1_clicked\0"
    "on_num2_clicked\0on_num3_clicked\0"
    "on_num4_clicked\0on_num5_clicked\0"
    "on_num6_clicked\0on_num7_clicked\0"
    "on_num8_clicked\0on_num9_clicked\0"
    "on_num0_clicked\0valider"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinCode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PinCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PinCode *_t = static_cast<PinCode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_retr_clicked(); break;
        case 1: _t->on_num1_clicked(); break;
        case 2: _t->on_num2_clicked(); break;
        case 3: _t->on_num3_clicked(); break;
        case 4: _t->on_num4_clicked(); break;
        case 5: _t->on_num5_clicked(); break;
        case 6: _t->on_num6_clicked(); break;
        case 7: _t->on_num7_clicked(); break;
        case 8: _t->on_num8_clicked(); break;
        case 9: _t->on_num9_clicked(); break;
        case 10: _t->on_num0_clicked(); break;
        case 11: _t->valider(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PinCode::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PinCode.data,
      qt_meta_data_PinCode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PinCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PinCode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PinCode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PinCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
