#pragma once

#include <cstring>
#include <cwchar>

class c_unknown_interface {
public:
    virtual __int64 max_block_count() = 0;
    virtual int max_text_length() = 0;
    virtual wchar_t* text(int block_index) = 0;

public:
    wchar_t* data;

public:
    void set_text(const wchar_t* text) {
        for (int i = 0; i < max_block_count(); ++i) {
            wcscpy_s(this->text(i), this->max_text_length(), text);
        }
    }
};

//.rdata:0000000180769F28 off_180769F28   dq offset sub_1800E0584 ; DATA XREF: c_scenario_map_info_interface__new+19F↑o
//.rdata:0000000180769F30                 dq offset sub_1800E0578
//.rdata:0000000180769F38                 dq offset sub_180081F20
//.rdata:0000000180769F40                 dq offset sub_1800E05A0
//.rdata:0000000180769F48                 dq offset sub_1800E05A8
//.rdata:0000000180769F50                 dq offset sub_180009BC0
//.rdata:0000000180769F58                 dq offset sub_180009BC0
//.rdata:0000000180769F60                 dq offset sub_1800575E0

class c_unknown_interface_2 {
public:

};

class c_scenario_map_info_interface {
public:
    virtual void free() = 0;
    virtual bool get_map_info(OUT char** buf, OUT int* len) = 0;
    virtual c_unknown_interface* name() = 0;
    virtual c_unknown_interface* description() = 0;

    virtual __int64 max_block_count() = 0; // 4
    virtual __int64 data_2() = 0; // 12
    virtual __int64 data_3() = 0; // 0
    virtual __int64 data_4() = 0; // a1 + 24;

    virtual int* get_flags(int* flags) = 0;
    virtual int set_flags(int flags) = 0;

    virtual c_unknown_interface_2* get_block(int index) = 0; // index < 4;
    virtual char* map_name() = 0; // max: 0x100
    virtual char get_data_7(int index) = 0; // index < D;
    virtual bool set_data_7(int index, bool value) = 0; // index < D;

    virtual int unused_0() = 0;
    virtual int unused_1() = 0;

    virtual void copy_data() = 0;

public:
    void set_map_name(const char* name) {
        wchar_t buffer[0x100] = { 0 };

        strcpy_s(this->map_name(), 0x100, name);

        swprintf(buffer, 0x100, L"%hs", name);

        this->name()->set_text(buffer);

        this->description()->set_text(buffer);
    }
};