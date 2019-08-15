open ReactNative;

// Checks the auth status and send to a route. This got the unmounted app warnings to stop though still learning why.
let checkAuthWithRoute = (~navigation: ReactNavigation.navigationProp(unit)) =>
  AsyncStorage.getItem("userToken")
  |> Js.Promise.then_(stringOrNull => {
       // This will switch to the App screen or Auth screen and this loading screen will be unmounted and thrown away.

       Js.log2("CHECKING_AUTH_TOKEN", stringOrNull);
       switch (Js.Null.toOption(stringOrNull)) {
       | None => Js.Promise.resolve(navigation##push("SignIn"))
       | Some(_stringOrNull) => Js.Promise.resolve(navigation##push("App"))
       };
     });

let signOutAsync = (~navigation: ReactNavigation.navigationProp(unit)) => {
  Js.Promise.
    /* begin call to AsyncStorage */
    (
      AsyncStorage.clear()
      |> then_(_result =>
           {
             resolve(navigation##push("AuthLoading"));
           }
           |> resolve
         )
      |> ignore
    );
};

let signInAsync = (~navigation: ReactNavigation.navigationProp(unit)) => {
  Js.Promise.
    /* begin call to AsyncStorage */
    (
      AsyncStorage.setItem("userToken", "abc")
      |> then_(_result =>
           {
             resolve(navigation##push("App"));
           }
           // resolve(navigation##push("AuthLoading"));
           |> resolve
         )
      |> ignore
    )};