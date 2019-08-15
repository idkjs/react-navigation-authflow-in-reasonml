open GlobalStyle;
open ReactNative;

[@react.component]
let make = (~navigation: ReactNavigation.navigationProp(unit)) => {
  let _showMoreApp = () => {
    navigation##push("Other");
  };
 
  <View style=styles##container>
    <Button title="Show me more of the app" onPress={_ => _showMoreApp()} />
    <Button title="Actually, sign me out :)" onPress={_ => Utils.signOutAsync(~navigation)} />
  </View>;
};