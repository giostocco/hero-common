/*
   Copyright (c) 2015, The Dokdo Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   File Name : init_sec.c
   Create Date : 2015.11.03
   Author : Sunghun Ra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <android-base/properties.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

enum device_variant {
    UNKNOWN = -1,
    G930F,
    G930S,
    G930K,
    G930L,
    G930W8,
    G935F,
    G935S,
    G935K,
    G935L,
    G935W8,
};

namespace android {
namespace init {

void vendor_load_properties()
{	
    std::string platform = android::base::GetProperty("ro.board.platform", "");
    std::string bootloader = android::base::GetProperty("ro.bootloader", "");
	device_variant variant = UNKNOWN;

    if (platform != ANDROID_TARGET) {
        return;
    }

    if (bootloader.find("G930F") != std::string::npos) {
        variant = G930F;
    } else if (bootloader.find("G930S") != std::string::npos) {
        variant = G930S;
    } else if (bootloader.find("G930K") != std::string::npos) {
        variant = G930K;
    } else if (bootloader.find("G930L") != std::string::npos) {
        variant = G930L;
    } else if (bootloader.find("G930W8") != std::string::npos) {
        variant = G930W8;
    } else if (bootloader.find("G935F") != std::string::npos) {
        variant = G935F;
    } else if (bootloader.find("G935S") != std::string::npos) {
        variant = G935S;
    } else if (bootloader.find("G935K") != std::string::npos) {
        variant = G935K;
    } else if (bootloader.find("G935L") != std::string::npos) {
        variant = G935L;
    } else if (bootloader.find("G935W8") != std::string::npos) {
        variant = G935W8;
    } else {
		return;
    }

    switch (variant) {
        case G930F:
            /* heroltexx */
            android::base::SetProperty("ro.build.fingerprint", "samsung/heroltexx/herolte:7.0/NRD90M/G930FXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "heroltexx-user 7.0 NRD90M G930FXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G930F");
            android::base::SetProperty("ro.product.device", "heroltexx");
            break;
        case G930W8:
            /* heroltebmc */
            android::base::SetProperty("ro.build.fingerprint", "samsung/heroltebmc/herolte:7.0/NRD90M/G930W8XXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "heroltebmc-user 7.0 NRD90M G930W8XXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G930W8");
            android::base::SetProperty("ro.product.device", "heroltebmc");
            break;
        case G930S:
            /* herolteskt */
            android::base::SetProperty("ro.build.fingerprint", "samsung/herolteskt/herolte:7.0/NRD90M/G930SXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "herolteskt-user 7.0 NRD90M G930SXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G930S");
            android::base::SetProperty("ro.product.device", "herolteskt");
            break;
        case G930K:
            /* heroltektt */
            android::base::SetProperty("ro.build.fingerprint", "samsung/heroltektt/herolte:7.0/NRD90M/G930KXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "heroltektt-user 7.0 NRD90M G930KXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G930K");
            android::base::SetProperty("ro.product.device", "heroltektt");
            break;
        case G930L:
            /* heroltelgt */
            android::base::SetProperty("ro.build.fingerprint", "samsung/heroltelgt/herolte:7.0/NRD90M/G930LXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "heroltelgt-user 7.0 NRD90M G930LXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G930L");
            android::base::SetProperty("ro.product.device", "heroltelgt");
            break;
        case G935W8:
            /* hero2ltebmc */
            android::base::SetProperty("ro.build.fingerprint", "samsung/hero2ltebmc/hero2lte:7.0/NRD90M/G935W8XXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "hero2ltebmc-user 7.0 NRD90M G935W8XXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G935W8");
            android::base::SetProperty("ro.product.device", "hero2ltebmc");
            break;
        case G935S:
            /* hero2lteskt */
            android::base::SetProperty("ro.build.fingerprint", "samsung/hero2lteskt/hero2lte:7.0/NRD90M/G935SXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "hero2lteskt-user 7.0 NRD90M G935SXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G935S");
            android::base::SetProperty("ro.product.device", "hero2lteskt");
            break;
        case G935K:
            /* hero2ltektt */
            android::base::SetProperty("ro.build.fingerprint", "samsung/hero2ltektt/hero2lte:7.0/NRD90M/G935KXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "hero2ltektt-user 7.0 NRD90M G935KXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G935K");
            android::base::SetProperty("ro.product.device", "hero2ltektt");
            break;
        case G935L:
            /* hero2ltelgt */
            android::base::SetProperty("ro.build.fingerprint", "samsung/hero2ltelgt/hero2lte:7.0/NRD90M/G935LXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "hero2ltelgt-user 7.0 NRD90M G935LXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G935L");
            android::base::SetProperty("ro.product.device", "hero2ltelgt");
            break;
            /* hero2ltexx */
            android::base::SetProperty("ro.build.fingerprint", "samsung/hero2ltexx/hero2lte:7.0/NRD90M/G935FXXU1ZPLH:user/release-keys");
            android::base::SetProperty("ro.build.description", "hero2ltexx-user 7.0 NRD90M G935FXXU1ZPLH release-keys");
            android::base::SetProperty("ro.product.model", "SM-G935F");
            android::base::SetProperty("ro.product.device", "hero2ltexx");
            break;
        default:
            return;
    }
    std::string device = android::base::GetProperty("ro.product.device", "");
}

}
}
