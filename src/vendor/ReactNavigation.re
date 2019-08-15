type navigationProp('routeParams) = {
  .
  [@bs.meth] "push": string => unit,
  [@bs.meth] "goBack": unit => unit,
  "state": {
    .
    "key": string,
    "routeName": string,
    "params": 'routeParams,
  },
};
[@bs.deriving abstract]
type screenOptions = {
  [@bs.optional]
  title: string,
};

type stackNavigatorConfig;

[@bs.obj]
external stackNavigatorConfig:
  (~headerMode: [@bs.string] [ | `float | `screen | `none]=?,
      ~initialRouteName: string=?,
       unit) =>
  stackNavigatorConfig =
  "";

[@bs.module "react-navigation"]
external createStackNavigator:
  (Js.t('a), stackNavigatorConfig) => React.element =
  "createStackNavigator";

type switchNavigatorConfig;
[@bs.obj]
external switchNavigatorConfig:
  (
    ~headerMode: [@bs.string] [ | `float | `screen | `none]=?,
    ~initialRouteName: string=?,
    ~screenOptions: screenOptions=?,
    unit
  ) =>
  switchNavigatorConfig =
  "";

[@bs.module "react-navigation"]
external createSwitchNavigator:
  (Js.t('a), switchNavigatorConfig) => React.element =
  "createSwitchNavigator";

[@bs.module "react-navigation"]
external createBottomTabNavigator: array(React.element) => React.element =
  "createBottomTabNavigator";

[@bs.module "react-navigation"]
external createAppContainer: React.element => React.element =
  "createAppContainer";