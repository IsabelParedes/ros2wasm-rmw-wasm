#include "rmw_wasm_cpp/rmw_identifier.hpp"

#include "rmw/rmw.h"
#include "rmw/impl/cpp/macros.hpp"
#include "rmw/topic_endpoint_info_array.h"
#include "rmw/get_topic_endpoint_info.h"

extern "C"
{

    static rmw_ret_t _get_info_by_topic(
        const rmw_node_t * node,
        rcutils_allocator_t * allocator,
        const char * topic_name,
        [[maybe_unused]] bool no_mangle,
        rmw_topic_endpoint_info_array_t * publishers_info)
    {   
        std::cout << "[WASM] _get_info_by_topic(start)\n"; // REMOVE
        RMW_CHECK_ARGUMENT_FOR_NULL(node, RMW_RET_INVALID_ARGUMENT);
        RMW_CHECK_TYPE_IDENTIFIERS_MATCH(
            node,
            node->implementation_identifier,
            rmw_wasm_cpp::identifier,
            return RMW_RET_INCORRECT_RMW_IMPLEMENTATION);
        RCUTILS_CHECK_ALLOCATOR(allocator, return RMW_RET_INVALID_ARGUMENT);
        RMW_CHECK_ARGUMENT_FOR_NULL(topic_name, RMW_RET_INVALID_ARGUMENT);
        if (RMW_RET_OK != rmw_topic_endpoint_info_array_check_zero(publishers_info)) {
            return RMW_RET_INVALID_ARGUMENT;
        }

        // TODO: figure out
        std::cout << "[WASM] _get_info_by_topic(end)\n"; // REMOVE
        return RMW_RET_OK;
    }

    rmw_ret_t rmw_get_publishers_info_by_topic(
        const rmw_node_t * node,
        rcutils_allocator_t * allocator,
        const char * topic_name,
        bool no_mangle,
        rmw_topic_endpoint_info_array_t * subscriptions_info)
    {
        // TODO: check if needs to be different
        std::cout << "[WASM] rmw_get_publishers_info_by_topic()\n"; // REMOVE
        return _get_info_by_topic(
            node,
            allocator,
            topic_name,
            no_mangle,
            subscriptions_info);
    }

    rmw_ret_t rmw_get_subscriptions_info_by_topic(
        const rmw_node_t * node,
        rcutils_allocator_t * allocator,
        const char * topic_name,
        bool no_mangle,
        rmw_topic_endpoint_info_array_t * subscriptions_info)
    {
        // TODO: check if needs to be different
        std::cout << "[WASM] rmw_get_subscriptions_info_by_topic()\n"; // REMOVE
        return _get_info_by_topic(
            node,
            allocator,
            topic_name,
            no_mangle,
            subscriptions_info);
    }

}