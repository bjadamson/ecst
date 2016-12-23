// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config.hpp>
#include <ecst/aliases.hpp>
#include <ecst/utils.hpp>
#include <ecst/thread_pool.hpp>
#include <ecst/settings.hpp>
#include <ecst/mp.hpp>
#include <ecst/context/bitset.hpp>
#include <ecst/context/scheduler.hpp>
#include <ecst/context/system.hpp>
#include <ecst/context/storage.hpp>
#include <tuple>

ECST_CONTEXT_NAMESPACE
{
    namespace impl
    {
        /// @brief Class managing systems and threads.
        /// @details Contains a thread pool, and a system storage.
        template <typename TSettings>
        class system_manager
        {
            template <typename>
            friend class data;

        public:
            using settings_type = TSettings;
            using thread_pool = ecst::thread_pool;

            using system_storage_type = // .
                context::storage::system::dispatch<settings_type>;

            using scheduler_type = // .
                typename settings::impl::ctx_scheduler<
                    settings_type>::template instantiate<settings_type>;

            template <typename T>
            using system_from_tag = tag::system::unwrap<T>;

        private:
            std::unique_ptr<thread_pool> _thread_pool{
                std::make_unique<thread_pool>()};

            system_storage_type _system_storage;

            scheduler_type _scheduler;

        public:
            /// @brief Executes `f` on all systems, sequentially.
            template <typename TF>
            void for_instances_sequential(TF&& f);

            /// @brief Executes `f` on all systems, in parallel.
            template <typename TF>
            void for_instances_parallel(TF&& f);

            /// @brief Executes `f` on all systems, in parallel if enabled by
            /// settings, sequentially otherwise.
            template <typename TF>
            void for_instances_dispatch(TF&& f);

            template <typename TF>
            auto post_in_thread_pool(TF&& f);

            template <typename TID>
            auto& instance_by_id(TID) noexcept;

        private:
            /// @brief Executes all the system chains starting with tags in
            /// `sstl`, overloading `fs...`.
            template <typename TContext, typename TStartSystemTagList,
                typename... TFs>
            void execute_systems_impl(
                TContext&, TStartSystemTagList sstl, TFs&&... fs);

        protected:
            /// @brief Returns a variadic lambda accepting system execution
            /// functions that will be executed on all dependency chains
            /// starting from `sts...`.
            template <typename TContext, typename... TStartSystemTags>
            auto execute_systems_from(
                TContext& context, TStartSystemTags... sts) noexcept;

            /// @brief Returns a variadic lambda accepting system execution
            /// functions that will be executed on all dependency chains
            /// starting from `sts...`.
            template <typename TContext, typename TStartSystemTags>
            auto execute_systems_from(
                TContext& context, std::tuple<TStartSystemTags> &&) noexcept;

            /// @brief Returns a variadic lambda accepting system execution
            /// functions that will be executed on all dependency chains
            /// starting from all independent systems in the context.
            template <typename TContext>
            auto execute_systems(TContext& context) noexcept;

        public:
            template <typename TSystemTag, typename TF>
            decltype(auto) for_system_outputs(TSystemTag, TF&& f);

            template <typename TSystemTag>
            auto& instance(TSystemTag) noexcept;

            template <typename TSystemTag>
            const auto& instance(TSystemTag) const noexcept;

            template <typename TSystemTag>
            auto& system(TSystemTag) noexcept;

            template <typename TSystemTag>
            const auto& system(TSystemTag) const noexcept;

            template <typename TSystemTag>
            auto is_in_system(TSystemTag, entity_id) const noexcept;

            template <typename TSystemTag>
            auto count_entities_in(TSystemTag) const noexcept;

            template <typename TSystemTag>
            auto any_entity_in(TSystemTag) const noexcept;

            // TODO:
            constexpr auto inner_parallelism_allowed() const noexcept;
        };
    }
}
ECST_CONTEXT_NAMESPACE_END
