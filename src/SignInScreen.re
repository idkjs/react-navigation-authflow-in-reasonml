open ReactNative;
open GlobalStyle;

[@react.component]
let make = (~navigation: ReactNavigation.navigationProp(unit)) => {
  <View style=styles##container>
    <Button title="Sign in!" onPress={_ => Utils.signInAsync(~navigation)} />
  </View>;
};