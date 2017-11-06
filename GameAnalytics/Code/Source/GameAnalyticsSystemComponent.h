
#pragma once

#include <AzCore/Component/Component.h>

#include <GameAnalytics/GameAnalyticsBus.h>

namespace GameAnalytics
{
    class GameAnalyticsSystemComponent
        : public AZ::Component
        , protected GameAnalyticsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(GameAnalyticsSystemComponent, "{DA11E36F-7615-4781-8297-0E49E862F9BA}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // GameAnalyticsRequestBus interface implementation.

        ////////////////////////////////////////////////////////////////////////

        // configure calls should be used before initialize
        void ConfigureAvailableCustomDimensions01(const AZStd::vector<string>& customDimensions) override;
        void ConfigureAvailableCustomDimensions02(const AZStd::vector<string>& customDimensions) override;
        void ConfigureAvailableCustomDimensions03(const AZStd::vector<string>& customDimensions) override;
        void ConfigureAvailableResourceCurrencies(const AZStd::vector<string>& resourceCurrencies) override;
        void ConfigureAvailableResourceItemTypes(const AZStd::vector<string>& resourceItemTypes) override;
        void ConfigureBuild(const string& build) override;

        void ConfigureUserId(const string& uId) override;

        // initialize - starting SDK (need configuration before starting)
        void Initialize(const string& gameKey, const string& gameSecret) override;

        // add events
        void AddBusinessEvent(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType) override;
#if defined(IOS)
        void AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt) override;
        void AddBusinessEventWithAutoFetchReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType) override;
#elif defined(ANDROID)
        void AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt, const string& signature) override;
#endif

        void AddResourceEvent(EGAResourceFlowType flowType, const string& currency, float amount, const string&itemType, const string& itemId) override;

        void AddProgressionEvent(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03) override;
        void AddProgressionEventWithScore(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03, int score) override;

        void AddDesignEvent(const string& eventId) override;
        void AddDesignEventWithValue(const string& eventId, double value) override;

        void AddErrorEvent(EGAErrorSeverity severity, const string& message) override;

        // set calls can be changed at any time (pre- and post-initialize)
        // some calls only work after a configure is called (setCustomDimension)
        void SetEnabledInfoLog(bool flag) override;
        void SetEnabledVerboseLog(bool flag) override;
        void SetEnabledManualSessionHandling(bool flag) override;
        void SetCustomDimension01(const string& dimension01) override;
        void SetCustomDimension02(const string& dimension02) override;
        void SetCustomDimension03(const string& dimension03) override;
        void SetFacebookId(const string& facebookId) override;
        void SetGender(EGAGender gender) override;
        void SetBirthYear(int birthYear) override;

        void StartSession() override;
        void EndSession() override;

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////

    private:
        static string const VERSION;
    };
}
