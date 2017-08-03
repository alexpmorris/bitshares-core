#pragma once

#include <graphene/app/plugin.hpp>

namespace graphene { namespace plugin { namespace hello {

namespace detail {
 class hello_plugin_impl;
}

class hello_plugin : public graphene::app::plugin
{
   public:
      /**
       * The plugin requires a constructor which takes app.  This is called regardless of whether the plugin is loaded.
       * The app parameter should be passed up to the superclass constructor.
       */
      hello_plugin();

      /**
       * Plugin is destroyed via base class pointer, so a virtual destructor must be provided.
       */
      virtual ~hello_plugin();

      /**
       * Every plugin needs a name.
       */
      virtual std::string plugin_name()const override;

      /**
       * Called when the plugin is enabled, but before the database has been created.
       */
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;

      /**
       * Called when the plugin is enabled.
       */
      virtual void plugin_startup() override;

      /**
       * Called when the plugin is shut down.
       */
      virtual void plugin_shutdown() override;

   private:
      std::shared_ptr< detail::hello_plugin_impl > my;
};

} } }
