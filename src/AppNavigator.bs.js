// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as HomeScreen from "./HomeScreen.bs.js";
import * as OtherScreen from "./OtherScreen.bs.js";
import * as SignInScreen from "./SignInScreen.bs.js";
import * as ReactNavigation from "react-navigation";
import * as AuthLoadingScreen from "./AuthLoadingScreen.bs.js";

var appStack = ReactNavigation.createStackNavigator({
      Home: HomeScreen.make,
      Other: OtherScreen.make
    }, {
      headerMode: "none"
    });

var authLoadingStack = ReactNavigation.createStackNavigator({
      AuthLoading: AuthLoadingScreen.make,
      App: appStack
    }, {
      headerMode: "none"
    });

var authStack = ReactNavigation.createStackNavigator({
      SignIn: SignInScreen.make
    }, {
      headerMode: "none"
    });

var $$default = ReactNavigation.createAppContainer(ReactNavigation.createSwitchNavigator({
          AuthLoading: authLoadingStack,
          App: appStack,
          Auth: authStack
        }, {
          initialRouteName: "AuthLoading"
        }));

export {
  appStack ,
  authLoadingStack ,
  authStack ,
  $$default ,
  $$default as default,
  
}
/* appStack Not a pure module */
