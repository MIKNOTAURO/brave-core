/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_FREQUENCY_CAPPING_EXCLUSION_RULES_DISMISSED_FREQUENCY_CAP_H_  // NOLINT
#define BAT_ADS_INTERNAL_FREQUENCY_CAPPING_EXCLUSION_RULES_DISMISSED_FREQUENCY_CAP_H_  // NOLINT

#include <stdint.h>
#include <deque>
#include <string>

#include "bat/ads/internal/frequency_capping/exclusion_rule.h"

namespace ads {

class AdsImpl;
struct CreativeAdInfo;

class DismissedFrequencyCap : public ExclusionRule {
 public:
  DismissedFrequencyCap(
      const AdsImpl* const ads);

  ~DismissedFrequencyCap() override;

  bool ShouldExclude(
      const CreativeAdInfo& ad) override;

  const std::string& get_last_message() const override;

 private:
  const AdsImpl* const ads_;  // NOT OWNED

  std::string last_message_;

  std::deque<AdHistory> GetHistory(
      const std::string& campaign_id) const;

  bool DoesAdRespectCap(
      const CreativeAdInfo& ad) const;
};

}  // namespace ads


#endif  // BAT_ADS_INTERNAL_FREQUENCY_CAPPING_EXCLUSION_RULES_DISMISSED_FREQUENCY_CAP_H_  // NOLINT
