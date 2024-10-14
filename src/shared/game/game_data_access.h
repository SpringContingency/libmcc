#pragma once

#include "./game_engine_variant.h"
#include "../scenario/scenario_map_variant.h"
#include "../scenario/scenario_map_info.h"
#include "../saved_games/saved_film.h"

class c_off_180769E58_interface {
public:
    virtual void free() = 0;
    virtual void* unknown_0() = 0;
    virtual void* unknown_1() = 0;
    virtual void* unknown_2() = 0;
    virtual void* unknown_3() = 0;
    virtual void* unknown_4() = 0;
    virtual void* unknown_5() = 0;
    virtual void* unknown_6() = 0;
    virtual void* unknown_7() = 0;
};

class c_game_data_access_interface {
public:
    virtual void free() = 0;
    virtual c_scenario_map_variant_interface* MapVariantCreateFromFile(char* buf, size_t len) = 0;
    virtual c_scenario_map_variant_interface* MapVariantCreateFromMapID(const s_map_id* map_id) = 0;
    virtual c_scenario_map_variant_interface* MapVariantCreateDefault(char* buf) = 0;
    virtual c_game_engine_variant_interface* GameVariantCreateFromFile(char* buf, size_t len) = 0;
    virtual c_game_engine_variant_interface* GameVariantCreateDefault(char* buf) = 0;
    virtual bool unused_0() = 0;
    virtual c_saved_film_interface* SaveFilmMetadataCreateFromFile(char* buf, size_t len) = 0;
    virtual bool unused_1() = 0;
    virtual c_off_180769E58_interface* off_180769E58_new() = 0;
    virtual void* data2_new(char* buf, int len) = 0;
    virtual c_scenario_map_info_interface* MapInfoCreate(IN OPTIONAL char* buf, IN OPTIONAL int* len) = 0;
    virtual bool unused_2() = 0;
    virtual int unknown_1(int value) = 0;
    virtual int unknown_2(void* value) = 0;
    virtual int unused_3() = 0;
    virtual int unused_4() = 0;
};