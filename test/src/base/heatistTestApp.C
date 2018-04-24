#include "heatistTestApp.h"
#include "heatistApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<heatistTestApp>()
{
  InputParameters params = validParams<heatistApp>();
  return params;
}

heatistTestApp::heatistTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  heatistApp::registerObjectDepends(_factory);
  heatistApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  heatistApp::associateSyntaxDepends(_syntax, _action_factory);
  heatistApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    heatistTestApp::registerObjects(_factory);
    heatistTestApp::associateSyntax(_syntax, _action_factory);
  }
}

heatistTestApp::~heatistTestApp() {}

void
heatistTestApp::registerApps()
{
  registerApp(heatistApp);
  registerApp(heatistTestApp);
}

void
heatistTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
heatistTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
heatistTestApp__registerApps()
{
  heatistTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
heatistTestApp__registerObjects(Factory & factory)
{
  heatistTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
heatistTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  heatistTestApp::associateSyntax(syntax, action_factory);
}
