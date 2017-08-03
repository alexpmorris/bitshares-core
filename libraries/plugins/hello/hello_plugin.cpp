#include <graphene/plugins/hello/hello_api.hpp>
#include <graphene/plugins/hello/hello_plugin.hpp>

#include <string>

namespace graphene { namespace plugin { namespace hello {

namespace detail {

class hello_plugin_impl
{
   public:
      hello_plugin_impl();
      virtual ~hello_plugin_impl();

      virtual std::string plugin_name()const;
      virtual void plugin_initialize( const boost::program_options::variables_map& options );
      virtual void plugin_startup();
      virtual void plugin_shutdown();
};

hello_plugin_impl::hello_plugin_impl()
{
}

hello_plugin_impl::~hello_plugin_impl() {}

std::string hello_plugin_impl::plugin_name()const
{
   return "hello_api";
}

void hello_plugin_impl::plugin_initialize( const boost::program_options::variables_map& options )
{
}

void hello_plugin_impl::plugin_startup()
{
}

void hello_plugin_impl::plugin_shutdown()
{
}

}

hello_plugin::hello_plugin() :
   my( new detail::hello_plugin_impl )
{
}

hello_plugin::~hello_plugin() {}

std::string hello_plugin::plugin_name()const
{
   return my->plugin_name();
}

void hello_plugin::plugin_initialize( const boost::program_options::variables_map& options )
{
   my->plugin_initialize( options );
}

void hello_plugin::plugin_startup()
{
   my->plugin_startup();
}

void hello_plugin::plugin_shutdown()
{
   my->plugin_shutdown();
}

} } } // graphene::plugin::hello
