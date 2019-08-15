# ReasonReactNavigation AuthFlow


<kbd>
<img src="./images/SignIn.png" alt="signIn" width="200"/></kbd>

<kbd>
<img src="./images/HomeScreen.png" alt="homeScreen" width="200"/></kbd>

<kbd>
<img src="./images/OtherScreen.png" alt="otherScreen" width="200"/></kbd>


## Motivation

Replicate the `react-navigation` AuthFlow Demo in ReasonML. The demo is here: <https://reactnavigation.org/docs/en/auth-flow.html>. I needed to understand how to get some basic `switch` and `stack` navigation working together in `ReasonML`. The binding for navigation are `WIP` at the excellent [reason-react-native](https://github.com/reasonml-community/reason-react-native) repo. More broadly, learning this on the fly takes time and to reduce the scope of what I have to learn, I decided I would try to limit myself to using react-native/react-native-web, in #ReasonML, of course, for all ui moving forward. That means I had to get some basic routing worked out for any mobile app version.

This version is kinda rough around the edges. The screen transitions don't seem smooth. I am sure I will figured that out eventually. I am just getting started with ReactNavigation so I will get to that knowledge soon I guess.

## Takeaways

This error was new to me:

```bsh
Warning: Can't perform a React state update on an unmounted component. This is a no-op, but it indicates a memory leak in your application. To fix, cancel all subscriptions and asynchronous tasks in %s.%s, a useEffect cleanup function,
```

I didn't really understand this at first because the app was running but throwing this warning. After researching and asking around, I came to learn that I needed to `clean up` my `React.useEffect` function to unmount after checking the auth status of the user.

That was done in `src/AuthLoadingScreen.re` in:

```reason
  React.useEffect1(
    () => {
      Utils.checkAuthWithRoute(~navigation) |> ignore
      // cleanup function that does nothing
      // thanks to @thangngoc89 for the tip on cleaning up useEffect
      Some(() => ());
    },
    [||],
  );
```

The `Some(() => ());` is what got it mostly done. I continued to get the issue only when i refreshed the IOS simulator after the user was logged in. So since it was working without error when there was no user logged in, I tried to replicate that setup. I ended up sending the routing the signOut function back to the `AuthLoadingScreen.re` module and letting that component figure out where to go next. I have no idea if this is the recommended way to do things but it works for the purposes of this demo. All that is happening in `src/utils/Utils.re`. This has the unintended effect of cleaning up the rest of the view screens as I ended up calling most of the transition logic directly in the auth promises.

## Running the app

`git clone https://github.com/idkjs/react-navigation-authflow-in-reasonml.git`
`cd react-navigation-authflow-in-reasonml`
`yarn install`

 In another directory, run `yarn start` to start `expo`. Hit `i` in that terminal to open the app in the simulator. Or whatever other of the five ways that can be done.

You can find me at [@_idkjs](https://twitter.com/_idkjs) with any questions.
