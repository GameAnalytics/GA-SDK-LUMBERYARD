# GA-SDK-LUMBERYARD
GameAnalytics Lumberyard SDK.

Documentation can be found [here](https://gameanalytics.com/docs/lumberyard-sdk).

If you have any issues or feedback regarding the SDK, please contact our friendly support team [here](https://gameanalytics.com/contact).

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
**3.0.0**
* Remote Config calls have been updated and the old calls have deprecated. Please see GA documentation for the new SDK calls and migration guide
* A/B testing support added

**2.1.2**
* added check if log files and database can't be created

**2.1.1**
* removed std string and replaced it with c-strings for desktop platforms
* fixed hanging background thread when closing application for desktop platforms

**2.1.0**
* added enable/disable event submission function

**2.0.3**
* fixed business event validation

**2.0.2**
* fixed thread hanging on shutdown for desktop platforms

**2.0.1**
* fixed jni compile errors (android)

**2.0.0**
* added command center functionality

**1.1.12**
* added custom dimensions to design and error events

**1.1.11**
* fixed session length bug
* fixed not allowing to add events when session is not started

**1.1.10**
* added onquit function for when closing desktop applications (windows, mac, linux)

**1.1.9**
* updated for Lumberyard 1.11.1

**1.1.8**
* JNI memory leak bug fix (android)

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
