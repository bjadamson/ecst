// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <tuple>
#include <ecst/config.hpp>
#include <ecst/aliases.hpp>
#include "../defer.hpp"

ECST_CONTEXT_NAMESPACE
{
    namespace impl
    {
        template <typename TSettings>
        class data;

        namespace step
        {
            template <typename TSettings>
            class proxy : public defer::proxy<TSettings>
            {
            private:
                using settings_type = TSettings;
                using base_type = defer::proxy<settings_type>;
                using context_type = data<settings_type>;
                using refresh_state_type = defer::refresh_state<settings_type>;

            public:
                proxy(context_type&, refresh_state_type&) noexcept;

                template <typename... TStartSystemTags>
                auto execute_systems_from(TStartSystemTags... sts) noexcept;

                template <typename TStartSystemTags>
                auto execute_systems_from(std::tuple<TStartSystemTags> &&) noexcept;

                auto execute_systems() noexcept;
            };
        }
    }
}
ECST_CONTEXT_NAMESPACE_END
