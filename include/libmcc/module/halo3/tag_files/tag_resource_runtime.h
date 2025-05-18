#pragma once

#include "../native.h"
#include "./tag_resource_threading.h"
#include "../multithreading/threads.h"
#include "../memory/data.h"
#include "../cache/cache_files.h"

namespace libmcc::halo3 {
    struct s_header_file_location : s_datum_header {
        uint16_t flags;
        s_file_handle async_file_handle;
        s_file_handle overlapped_handle;
        s_indirect_file indirect_file;
        s_cache_file_shared_resource_usage* shared_resource_usage;
        int xdk_version;
        int resource_section_offset;
        int map_file_index;
    };

    struct c_cache_file_tag_resource_runtime_manager {
        c_wrapped_array<c_tag_resource_cache_file_access_cache*>* m_per_thread_access_cache() {
            return reinterpret_cast<c_wrapped_array<c_tag_resource_cache_file_access_cache*>*>(data + 0x2B9B0);
        };

        char data[1];
    };

    struct c_typed_allocation_data_no_destruct_c_cache_file_tag_resource_runtime_manager_1 {
        c_basic_buffer m_opaque_storage;
        c_cache_file_tag_resource_runtime_manager *m_live_object;
        c_allocation_base *m_allocator;
    };

    inline c_typed_allocation_data_no_destruct_c_cache_file_tag_resource_runtime_manager_1* g_resource_runtime_manager() {
        return REF<c_typed_allocation_data_no_destruct_c_cache_file_tag_resource_runtime_manager_1>(s_data_offset_table::g_resource_runtime_manager);
    }

    template <typename T>
    inline T* get_tag_resource(s_tag_resource* resource) {
        auto thread_index = g_thread_local_storage()->g_registered_thread_index;

        auto mananger = g_resource_runtime_manager();

        if (reinterpret_cast<int64_t>(mananger->m_live_object) == -177216) {
            return nullptr;
        }

        auto access_cache = mananger->m_live_object->m_per_thread_access_cache()->m_elements[thread_index];

        auto index = static_cast<uint16_t>(resource->resource_handle);

        return reinterpret_cast<T*>(access_cache->m_cached_access_datums.m_elements[index]);
    }

    template <typename T>
    inline T* get_tag(uint32_t address) {
        auto base_address = physical_memory_globals()->allocation_base_address;

        auto minimum_address = reinterpret_cast<int*>(base_address - k_tag_cache_minimum_address);

        return reinterpret_cast<T*>(minimum_address + address);
    }
}
