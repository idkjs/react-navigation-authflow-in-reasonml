open ReactNative;
open GlobalStyle;

[@react.component]
let make = (~navigation: ReactNavigation.navigationProp(unit)) => {
  React.useEffect1(
    () => {
      Utils.checkAuthWithRoute(~navigation) |> ignore
      // cleanup function that does nothing
      // thanks to @thangngoc89 for the tip on cleaning up useEffect
      Some(() => ());
    },
    [||],
  );

  <View style=styles##container>
     <ActivityIndicator /> <StatusBar barStyle=`default /> </View>;
};