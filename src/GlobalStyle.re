open ReactNative;
let styles =
  Style.(
    StyleSheet.create({
      "container":
        viewStyle(~justifyContent=`center, ~alignItems=`center, ~flex=1., ()),
      "header": style(~fontSize=25., ~marginBottom=5.->dp, ()),
    })
  );