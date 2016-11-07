
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/std/string/string.h>
#include <AzCore/std/containers/vector.h>

namespace GameAnalytics
{
    /*!
     @enum
     @discussion
     This enum is used to specify flow in resource events
     @constant GAResourceFlowTypeSource
     Used when adding to a resource currency
     @constant GAResourceFlowTypeSink
     Used when subtracting from a resource currency
     */
    enum EGAResourceFlowType
    {
        Source = 1,
        Sink = 2
    };

    /*!
     @enum
     @discussion
     his enum is used to specify status for progression event
     @constant GAProgressionStatusStart
     User started progression
     @constant GAProgressionStatusComplete
     User succesfully ended a progression
     @constant GAProgressionStatusFail
     User failed a progression
     */
    enum EGAProgressionStatus
    {
        Start = 1,
        Complete = 2,
        Fail = 3
    };

    /*!
     @enum
     @discussion
     his enum is used to specify severity of an error event
     @constant GAErrorSeverityDebug
     @constant GAErrorSeverityInfo
     @constant GAErrorSeverityWarning
     @constant GAErrorSeverityError
     @constant GAErrorSeverityCritical
     */
    enum EGAErrorSeverity
    {
        Debug = 1,
        Info = 2,
        Warning = 3,
        Error = 4,
        Critical = 5
    };

    enum EGAGender
    {
        Male = 1,
        Female = 2
    };

    class GameAnalyticsRequests : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////

        // Put your public methods here

        // configure calls should be used before initialize
        virtual void ConfigureAvailableCustomDimensions01(const AZStd::vector<string>& customDimensions) = 0;
        virtual void ConfigureAvailableCustomDimensions02(const AZStd::vector<string>& customDimensions) = 0;
        virtual void ConfigureAvailableCustomDimensions03(const AZStd::vector<string>& customDimensions) = 0;
        virtual void ConfigureAvailableResourceCurrencies(const AZStd::vector<string>& resourceCurrencies) = 0;
        virtual void ConfigureAvailableResourceItemTypes(const AZStd::vector<string>& resourceItemTypes) = 0;
        virtual void ConfigureBuild(const string& build) = 0;

        virtual void ConfigureUserId(const string& uId) = 0;

        // initialize - starting SDK (need configuration before starting)
        virtual void Initialize(const string& gameKey, const string& gameSecret) = 0;

        // add events
        virtual void AddBusinessEvent(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType) = 0;
#if defined(IOS)
        virtual void AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt) = 0;
        virtual void AddBusinessEventWithAutoFetchReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType) = 0;
#elif defined(ANDROID)
        virtual void AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt, const string& signature) = 0;
#endif

        virtual void AddResourceEvent(EGAResourceFlowType flowType, const string& currency, float amount, const string&itemType, const string& itemId) = 0;

        virtual void AddProgressionEvent(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03) = 0;
        virtual void AddProgressionEventWithScore(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03, int score) = 0;

        virtual void AddDesignEvent(const string& eventId) = 0;
        virtual void AddDesignEventWithValue(const string& eventId, double value) = 0;

        virtual void AddErrorEvent(EGAErrorSeverity severity, const string& message) = 0;

        // set calls can be changed at any time (pre- and post-initialize)
        // some calls only work after a configure is called (setCustomDimension)
        virtual void SetEnabledInfoLog(bool flag) = 0;
        virtual void SetEnabledVerboseLog(bool flag) = 0;
        virtual void SetEnabledManualSessionHandling(bool flag) = 0;
        virtual void SetCustomDimension01(const string& dimension01) = 0;
        virtual void SetCustomDimension02(const string& dimension02) = 0;
        virtual void SetCustomDimension03(const string& dimension03) = 0;
        virtual void SetFacebookId(const string& facebookId) = 0;
        virtual void SetGender(EGAGender gender) = 0;
        virtual void SetBirthYear(int birthYear) = 0;

        virtual void StartSession() = 0;
        virtual void EndSession() = 0;
    };
    using GameAnalyticsRequestBus = AZ::EBus<GameAnalyticsRequests>;
} // namespace GameAnalytics
