#import "GameAnalytics.h"
#import "GameAnalyticsCpp.h"

void GameAnalyticsCpp::configureAvailableCustomDimensions01(const std::vector<std::string>& list)
{
    NSMutableArray * tmpary = [[NSMutableArray alloc] initWithCapacity: list.size()];
    for (std::string s : list)
    {
        [tmpary addObject: @(s.c_str())];
    }
    NSArray *list_array = tmpary;
    [GameAnalytics configureAvailableCustomDimensions01:list_array];
}

void GameAnalyticsCpp::configureAvailableCustomDimensions02(const std::vector<std::string>& list)
{
    NSMutableArray * tmpary = [[NSMutableArray alloc] initWithCapacity: list.size()];
    for (std::string s : list)
    {
        [tmpary addObject: @(s.c_str())];
    }
    NSArray *list_array = tmpary;
    [GameAnalytics configureAvailableCustomDimensions02:list_array];
}

void GameAnalyticsCpp::configureAvailableCustomDimensions03(const std::vector<std::string>& list)
{
    NSMutableArray * tmpary = [[NSMutableArray alloc] initWithCapacity: list.size()];
    for (std::string s : list)
    {
        [tmpary addObject: @(s.c_str())];
    }
    NSArray *list_array = tmpary;
    [GameAnalytics configureAvailableCustomDimensions03:list_array];
}

void GameAnalyticsCpp::configureAvailableResourceCurrencies(const std::vector<std::string>& list)
{
    NSMutableArray * tmpary = [[NSMutableArray alloc] initWithCapacity: list.size()];
    for (std::string s : list)
    {
        [tmpary addObject: @(s.c_str())];
    }
    NSArray *list_array = tmpary;
    [GameAnalytics configureAvailableResourceCurrencies:list_array];
}

void GameAnalyticsCpp::configureAvailableResourceItemTypes(const std::vector<std::string>& list)
{
    NSMutableArray * tmpary = [[NSMutableArray alloc] initWithCapacity: list.size()];
    for (std::string s : list)
    {
        [tmpary addObject: @(s.c_str())];
    }
    NSArray *list_array = tmpary;
    [GameAnalytics configureAvailableResourceItemTypes:list_array];
}

void GameAnalyticsCpp::configureBuild(const char *build)
{
    NSString *buildString = build != NULL ? @(build) : nil;
    [GameAnalytics configureBuild:buildString];
}

void GameAnalyticsCpp::configureUserId(const char *userId)
{
    NSString *userIdString = userId != NULL ? @(userId) : nil;
    [GameAnalytics configureUserId:userIdString];
}

void GameAnalyticsCpp::configureSdkGameEngineVersion(const char *gameEngineSdkVersion)
{
    NSString *gameEngineSdkVersionString = gameEngineSdkVersion != NULL ? @(gameEngineSdkVersion) : nil;
    [GameAnalytics configureSdkVersion:gameEngineSdkVersionString];
}

void GameAnalyticsCpp::configureGameEngineVersion(const char *gameEngineVersion)
{
    NSString *gameEngineVersionString = gameEngineVersion != NULL ? @(gameEngineVersion) : nil;
    [GameAnalytics configureEngineVersion:gameEngineVersionString];
}

void GameAnalyticsCpp::initialize(const char *gameKey, const char *gameSecret)
{
    NSString *gameKeyString = gameKey != NULL ? @(gameKey) : nil;
    NSString *gameSecretString = gameSecret != NULL ? @(gameSecret) : nil;

    [GameAnalytics initializeWithGameKey:gameKeyString gameSecret:gameSecretString];
}

void GameAnalyticsCpp::addBusinessEvent(const char *currency, int amount, const char *itemType, const char *itemId, const char *cartType, const char *receipt)
{
    NSString *currencyString = currency != NULL ? @(currency) : nil;
    NSInteger amountInteger = (NSInteger)amount;
    NSString *itemTypeString = itemType != NULL ? @(itemType) : nil;
    NSString *itemIdString = itemId != NULL ? @(itemId) : nil;
    NSString *cartTypeString = cartType != NULL ? @(cartType) : nil;
    NSString *receiptString = receipt != NULL ? @(receipt) : nil;

    [GameAnalytics addBusinessEventWithCurrency:currencyString
                                         amount:amountInteger
                                       itemType:itemTypeString
                                         itemId:itemIdString
                                       cartType:cartTypeString
                                        receipt:receiptString];
}

void GameAnalyticsCpp::addBusinessEventAndAutoFetchReceipt(const char *currency, int amount, const char *itemType, const char *itemId, const char *cartType)
{
    NSString *currencyString = currency != NULL ? @(currency) : nil;
    NSInteger amountInteger = (NSInteger)amount;
    NSString *itemTypeString = itemType != NULL ? @(itemType) : nil;
    NSString *itemIdString = itemId != NULL ? @(itemId) : nil;
    NSString *cartTypeString = cartType != NULL ? @(cartType) : nil;

    [GameAnalytics addBusinessEventWithCurrency:currencyString
                                         amount:amountInteger
                                       itemType:itemTypeString
                                         itemId:itemIdString
                                       cartType:cartTypeString
                               autoFetchReceipt:true];
}

void GameAnalyticsCpp::addResourceEvent(int flowType, const char *currency, float amount, const char *itemType, const char *itemId)
{
    NSString *currencyString = currency != NULL ? @(currency) : nil;
    NSNumber *amountNumber = [NSNumber numberWithFloat:amount];
    NSString *itemTypeString = itemType != NULL ? @(itemType) : nil;
    NSString *itemIdString = itemId != NULL ? @(itemId) : nil;

    [GameAnalytics addResourceEventWithFlowType:(GAResourceFlowType)flowType
                                       currency:currencyString
                                         amount:amountNumber
                                       itemType:itemTypeString
                                         itemId:itemIdString];
}

void GameAnalyticsCpp::addProgressionEvent(int progressionStatus, const char *progression01, const char *progression02, const char *progression03)
{
    NSString *progression01String = progression01 != NULL ? @(progression01) : nil;
    NSString *progression02String = progression02 != NULL ? @(progression02) : nil;
    NSString *progression03String = progression03 != NULL ? @(progression03) : nil;

    [GameAnalytics addProgressionEventWithProgressionStatus:(GAProgressionStatus)progressionStatus
                                              progression01:progression01String
                                              progression02:progression02String
                                              progression03:progression03String];
}

void GameAnalyticsCpp::addProgressionEventWithScore(int progressionStatus, const char *progression01, const char *progression02, const char *progression03, int score)
{
    NSString *progression01String = progression01 != NULL ? @(progression01) : nil;
    NSString *progression02String = progression02 != NULL ? @(progression02) : nil;
    NSString *progression03String = progression03 != NULL ? @(progression03) : nil;

    [GameAnalytics addProgressionEventWithProgressionStatus:(GAProgressionStatus)progressionStatus
                                              progression01:progression01String
                                              progression02:progression02String
                                              progression03:progression03String
                                                      score:score];
}

void GameAnalyticsCpp::addDesignEvent(const char *eventId)
{
    NSString *eventIdString = eventId != NULL ? @(eventId) : nil;

    [GameAnalytics addDesignEventWithEventId:eventIdString value:nil];
}

void GameAnalyticsCpp::addDesignEventWithValue(const char *eventId, float value)
{
    NSString *eventIdString = eventId != NULL ? @(eventId) : nil;
    NSNumber *valueNumber = [NSNumber numberWithFloat:value];

    [GameAnalytics addDesignEventWithEventId:eventIdString value:valueNumber];
}

void GameAnalyticsCpp::addErrorEvent(int severity, const char *message)
{
    NSString *messageString = message != NULL ? @(message) : nil;

    [GameAnalytics addErrorEventWithSeverity:(GAErrorSeverity)severity message:messageString];
}

void GameAnalyticsCpp::setEnabledInfoLog(bool flag)
{
    [GameAnalytics setEnabledInfoLog:flag];
}

void GameAnalyticsCpp::setEnabledVerboseLog(bool flag)
{
    [GameAnalytics setEnabledVerboseLog:flag];
}

void GameAnalyticsCpp::setEnabledManualSessionHandling(bool flag)
{
    [GameAnalytics setEnabledManualSessionHandling:flag];
}

void GameAnalyticsCpp::setEnabledEventSubmission(bool flag)
{
    [GameAnalytics setEnabledEventSubmission:flag];
}

void GameAnalyticsCpp::setCustomDimension01(const char *customDimension)
{
    NSString *customDimensionString = customDimension != NULL ? @(customDimension) : nil;
    [GameAnalytics setCustomDimension01:customDimensionString];
}

void GameAnalyticsCpp::setCustomDimension02(const char *customDimension)
{
    NSString *customDimensionString = customDimension != NULL ? @(customDimension) : nil;
    [GameAnalytics setCustomDimension02:customDimensionString];
}

void GameAnalyticsCpp::setCustomDimension03(const char *customDimension)
{
    NSString *customDimensionString = customDimension != NULL ? @(customDimension) : nil;
    [GameAnalytics setCustomDimension03:customDimensionString];
}

void GameAnalyticsCpp::setFacebookId(const char *facebookId)
{
    NSString *facebookIdString = facebookId != NULL ? @(facebookId) : nil;
    [GameAnalytics setFacebookId:facebookIdString];
}

void GameAnalyticsCpp::setGender(const char *gender)
{
    NSString *genderString = gender != NULL ? @(gender) : nil;
    [GameAnalytics setGender:genderString];
}

void GameAnalyticsCpp::setBirthYear(int birthYear)
{
    NSInteger birthYearInteger = (NSInteger)birthYear;
    [GameAnalytics setBirthYear:birthYearInteger];
}

void GameAnalyticsCpp::startSession()
{
    [GameAnalytics startSession];
}

void GameAnalyticsCpp::endSession()
{
    [GameAnalytics endSession];
}

const char* GameAnalyticsCpp::getCommandCenterValueAsString(const char *key) {
    NSString *keyString = key != NULL ? [NSString stringWithUTF8String:key] : nil;
    NSString *result = [GameAnalytics getCommandCenterValueAsString:keyString];

    return result != nil ? [result UTF8String] : NULL;
}

const char* GameAnalyticsCpp::getCommandCenterValueAsString(const char *key, const char *defaultValue) {
    NSString *keyString = key != NULL ? [NSString stringWithUTF8String:key] : nil;
    NSString *defaultValueString = key != NULL ? [NSString stringWithUTF8String:defaultValue] : nil;
    NSString *result = [GameAnalytics getCommandCenterValueAsString:keyString defaultValue:defaultValue];

    return result != nil ? [result UTF8String] : NULL;
}

bool GameAnalyticsCpp::isCommandCenterReady() {
    return [GameAnalytics isCommandCenterReady] ? true : false;
}

const char* GameAnalyticsCpp::getConfigurationsContentAsString() {
    NSString *result = [GameAnalytics getCommandCenterConfigurations];

    return result != nil ? [result UTF8String] : NULL;
}
