
#pragma once

#include <fc/api.hpp>

namespace graphene { namespace app {
class application;
} }

namespace graphene { namespace plugin { namespace hello {

namespace detail {
class hello_api_impl;
}

class hello_api
{
   public:
      hello_api( graphene::app::application& app );

      /**
       * Called immediately after the constructor.  If the API class uses enable_shared_from_this,
       * shared_from_this() is available in this method, which allows signal handlers to be registered
       * with app::connect_signal()
       */
      void on_api_startup();

      // TODO:  Add API methods here
      void hello();

   private:
      std::shared_ptr< detail::hello_api_impl > my;
};

} } }

FC_API( graphene::plugin::hello::hello_api,
   // TODO:  Add method bubble list here
   (hello)
   )
