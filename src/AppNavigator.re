open ReactNavigation;
// const AppStack = createStackNavigator({ Home: HomeScreen, Other: OtherScreen });
// const AuthStack = createStackNavigator({ SignIn: SignInScreen });
let appStack =
  createStackNavigator(
    {"Home": HomeScreen.make, "Other": OtherScreen.make},
    stackNavigatorConfig(~headerMode=`none, ()),
  );
let authLoadingStack =
  createStackNavigator(
    {
      "AuthLoading": AuthLoadingScreen.make,
      "App": appStack,
    },
    stackNavigatorConfig(
      ~headerMode=`none,
      (),
    ),
  );

let authStack =
  createStackNavigator(
    {"SignIn": SignInScreen.make},
    stackNavigatorConfig(~headerMode=`none, ()),
  );

let default =
  ReactNavigation.createAppContainer(
    createSwitchNavigator(
      {
        "AuthLoading": authLoadingStack,
        "App": appStack,
        "Auth": authStack,
      },
      switchNavigatorConfig(~initialRouteName="AuthLoading", ()),
    ),
  );