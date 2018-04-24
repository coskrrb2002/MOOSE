#ifndef HEATISTTESTAPP_H
#define HEATISTTESTAPP_H

#include "MooseApp.h"

class heatistTestApp;

template <>
InputParameters validParams<heatistTestApp>();

class heatistTestApp : public MooseApp
{
public:
  heatistTestApp(InputParameters parameters);
  virtual ~heatistTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HEATISTTESTAPP_H */
