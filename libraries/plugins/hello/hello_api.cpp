#include <graphene/app/application.hpp>

#include <graphene/plugins/hello/hello_api.hpp>
#include <graphene/plugins/hello/hello_plugin.hpp>

namespace graphene { namespace plugin { namespace hello {

namespace detail {

class hello_api_impl
{
   public:
      hello_api_impl( graphene::app::application& _app );
      graphene::app::application& app;
      std::shared_ptr< graphene::plugin::hello::hello_plugin > get_plugin();

      // TODO:  Add API methods here
      void hello();
};

hello_api_impl::hello_api_impl( graphene::app::application& _app ) : app( _app )
{}

std::shared_ptr< graphene::plugin::hello::hello_plugin > hello_api_impl::get_plugin()
{
   return app.get_plugin< hello_plugin >( "hello_api" );
}

void hello_api_impl::hello()
{
   // do nothing
}

} // detail

hello_api::hello_api( graphene::app::application& app )
{
   my = std::make_shared< detail::hello_api_impl >(app);
}

void hello_api::on_api_startup() { }

void hello_api::hello()
{
   my->hello();
}

} } } // graphene::plugin::hello
