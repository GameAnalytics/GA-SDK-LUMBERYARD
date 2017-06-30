# GA-SDK-LUMBERYARD
GameAnalytics Lumberyard SDK.

Documentation is in the [wiki](https://github.com/GameAnalytics/GA-SDK-LUMBERYARD/wiki).

> :information_source:<br>
>
> The Lumberyard SDK include support for **iOS**, **Android**, **Windows**, **Linux** and **Mac** platforms
>
> Requirements:<br/>
> **Lumberyard:** 1.5.x+  
> **iOS:** iOS 7+<br/>
> **Android:** Android API Level 14<br>   
>   
> **Build size:**   
> Note that download size differ from the actual build size.   
>   
> **Android:**   
> The SDK build size in a native Android app is only around **49Kb** and the dependecies take up to **820Kb** depending if your app already uses some of the same dependencies.   
>   
> **iOS:**   
> The SDK build size in a native iOS app is only around **242Kb** (armv7) / **259Kb** (armv8).


Changelog
---------
<!--(CHANGELOG_TOP)-->
**1.1.7**
* jni bug fix for progression events with scores (android)

**1.1.6**
* adding correct files

**1.1.5**
* bug fix for progression events with score for android (android)

**1.1.4**
* bug fix for end session when using manual session handling

**1.1.3**
* session length precision improvement
* minor bug fixes
* updated for Lumberyard v1.8.0

**1.1.2**
* custom user id bug fix

**1.1.1**
* added vc140 libs

**1.1.0**
* added linux support
* added os version, device model and device manufacturer to events (windows mac)

**1.0.0**
* corrected validators in android and ios native libs

**0.1.1**
* possible to set custom dimensions and demographics before initialise

**0.1.0**
* First release
