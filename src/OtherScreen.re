open GlobalStyle;
open ReactNative;

[@react.component]
let make = (~navigation: ReactNavigation.navigationProp(unit)) => {

  <View style=styles##container>
    <Button
      title="I'm done, sign me out"
      onPress={_ => Utils.signOutAsync(~navigation)}
    />
    <StatusBar barStyle=`default />
  </View>;
};