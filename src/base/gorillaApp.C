#include "gorillaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
gorillaApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

gorillaApp::gorillaApp(InputParameters parameters) : MooseApp(parameters)
{
  gorillaApp::registerAll(_factory, _action_factory, _syntax);
}

gorillaApp::~gorillaApp() {}

void
gorillaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"gorillaApp"});
  Registry::registerActionsTo(af, {"gorillaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
gorillaApp::registerApps()
{
  registerApp(gorillaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
gorillaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  gorillaApp::registerAll(f, af, s);
}
extern "C" void
gorillaApp__registerApps()
{
  gorillaApp::registerApps();
}
