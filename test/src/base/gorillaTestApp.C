//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "gorillaTestApp.h"
#include "gorillaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
gorillaTestApp::validParams()
{
  InputParameters params = gorillaApp::validParams();
  return params;
}

gorillaTestApp::gorillaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  gorillaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

gorillaTestApp::~gorillaTestApp() {}

void
gorillaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  gorillaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"gorillaTestApp"});
    Registry::registerActionsTo(af, {"gorillaTestApp"});
  }
}

void
gorillaTestApp::registerApps()
{
  registerApp(gorillaApp);
  registerApp(gorillaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
gorillaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  gorillaTestApp::registerAll(f, af, s);
}
extern "C" void
gorillaTestApp__registerApps()
{
  gorillaTestApp::registerApps();
}
