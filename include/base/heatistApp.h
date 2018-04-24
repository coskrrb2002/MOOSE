#ifndef HEATISTAPP_H
#define HEATISTAPP_H

#include "MooseApp.h"

class heatistApp;

template <>
InputParameters validParams<heatistApp>();

class heatistApp : public MooseApp
{
public:
  heatistApp(InputParameters parameters);
  virtual ~heatistApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HEATISTAPP_H */
