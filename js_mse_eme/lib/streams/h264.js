/**
 * @license
 * Copyright 2020 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

(function() {

const PLAYREADY_SIGNATURE_1 =
    '448279561E2755699618BE0A2402189D4A30B03B.0CD6A27286BD2DAF00577FFA21928665DCD320C2';
const WIDEVINE_SIGNATURE_1 =
    '9C4BE99E6F517B51FED1F0B3B31966D3C5DAB9D6.6A1F30BB35F3A39A4CA814B731450D4CBD198FFD';
const WIDEVINE_L3NOHDCP_VIDEO_ID = 'f320151fa3f061b2';
const WIDEVINE_L3NOHDCP_SIGNATURE =
    '81E7B33929F9F35922F7D2E96A5E7AC36F3218B2.673F553EE51A48438AE5E707AEC87A071B4FEF65';

const H264_STREAMS = {
  streamtype: 'H264',
  mimetype: 'video/mp4; codecs="avc1.640028"',
  mediatype: 'video',
  container: 'mp4',
  streams: {
    VideoTiny: [
      'car-20120827-85.mp4', 6015001, 181.44, {
        'videoChangeRate': 11.47,
        'mimeType': 'video/mp4; codecs="avc1.4d4015"',
        'resolution': '240p'
      }
    ],
    VideoNormal: [
      'car-20120827-86.mp4', 15593225, 181.44,
      {'mimeType': 'video/mp4; codecs="avc1.4d401e"', 'resolution': '360p'}
    ],
    CarMedium: [
      'car09222016-med-134.mp4', 10150205, 181.47,
      {'mimeType': 'video/mp4; codecs="avc1.4d401e"', 'resolution': '360p'}
    ],
    VideoHuge: [
      'car-20120827-89.mp4', 95286345, 181.44,
      {'mimeType': 'video/mp4; codecs="avc1.640028"', 'resolution': '1080p'}
    ],
    Video1MB: [
      'test-video-1MB.mp4', 1053406, 1.04, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'resolution': '360p',
        'width': 480
      }
    ],
    VideoHeAac: [
      'test_stream_H264-HE-AAC.mp4', 6676977, 26.1, {
        'mimeType' : 'video/mp4; codecs="avc1.64001f"',
        'resolution': '480p',
        'width': 854
      }
    ],
    VideoNormalClearKey: [
      'car_cenc-20120827-86.mp4', 15795193, 181.44, {
        'mimeType': 'video/mp4; codecs="avc1.4d401e"',
        'key': util.createUint8ArrayFromJSArray([
          0x1a, 0x8a, 0x20, 0x95, 0xe4, 0xde, 0xb2, 0xd2, 0x9e, 0xc8, 0x16,
          0xac, 0x7b, 0xae, 0x20, 0x82
        ]),
        'kid': util.createUint8ArrayFromJSArray([
          0x60, 0x06, 0x1e, 0x01, 0x7e, 0x47, 0x7e, 0x87, 0x7e, 0x57, 0xd0,
          0x0d, 0x1e, 0xd0, 0x0d, 0x1e
        ]),
        'resolution': '360p',
      }
    ],
    VideoStreamYTCenc: [
      'oops_cenc-20121114-145-no-clear-start.mp4', 39980507, 242.71, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'video_id': '03681262dc412c06',
        'widevine_signature': WIDEVINE_SIGNATURE_1,
        'key': util.createUint8ArrayFromJSArray([
          233, 122, 210, 133, 203, 93, 59, 228, 167, 150, 27, 122, 246, 145,
          112, 218
        ]),
        'resolution': '720p',
      }
    ],
    VideoTinyStreamYTCenc: [
      'oops_cenc-20121114-145-143.mp4', 7229257, 30.03, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'resolution': '720p',
      }
    ],
    VideoSmallStreamYTCenc: [
      'oops_cenc-20121114-143-no-clear-start.mp4', 12045546, 242.71, {
        'mimeType': 'video/mp4; codecs="avc1.4d401e"',
        'key': util.createUint8ArrayFromJSArray([
          131, 162, 92, 175, 153, 178, 172, 41, 2, 167, 251, 126, 233, 215, 230,
          185
        ]),
        'resolution': '360p',
      }
    ],
    VideoSmallCenc: [
      'oops_cenc-20121114-142.mp4', 8017271, 242.71, {
        'mimeType': 'video/mp4; codecs="avc1.4d4015"',
        'video_id': '03681262dc412c06',
        'playready_signature': PLAYREADY_SIGNATURE_1,
        'widevine_signature': WIDEVINE_SIGNATURE_1,
        'resolution': '240p',
      }
    ],
    VideoMultiKeyCenc: [
      'tears_h264_main_720p_1500.mp4', 105466539, 734.17, {
        'mimetype': 'video/mp4; codecs="avc1.4d401f"',
        'pssh': util.createUint8ArrayFromJSArray([
          0,   0,   0,   68,  112, 115, 115, 104, 0,   0,   0,   0,   237, 239,
          139, 169, 121, 214, 74,  206, 163, 200, 39,  220, 213, 29,  33,  237,
          0,   0,   0,   36,  8,   1,   18,  1,   49,  26,  13,  119, 105, 100,
          101, 118, 105, 110, 101, 95,  116, 101, 115, 116, 34,  10,  50,  48,
          49,  53,  95,  116, 95,  49,  54,  107, 42,  2,   83,  68
        ]),
        'license_server': 'https://proxy.staging.widevine.com/proxy',
        'width': 1280,
        'height': 532,
      }
    ],
    DrmL3NoHDCP144p30fpsCenc: [
      'drml3NoHdcp_h264_144p_30fps_cenc.mp4', 1463083, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '144p',
      }
    ],
    DrmL3NoHDCP240p30fpsCenc: [
      'drml3NoHdcp_h264_240p_30fps_cenc.mp4', 3177191, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '240p',
      }
    ],
    DrmL3NoHDCP360p30fpsCenc: [
      'drml3NoHdcp_h264_360p_30fps_cenc.mp4', 7297992, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '360p',
      }
    ],
    DrmL3NoHDCP480p30fpsCenc: [
      'drml3NoHdcp_h264_480p_30fps_cenc.mp4', 14394742, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '480p',
      }
    ],
    DrmL3NoHDCP480p30fpsMqCenc: [
      'drml3NoHdcp_h264_480p_mq_30fps_cenc.mp4', 22118210, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '480p',
        'quality': 'MQ',
      }
    ],
    DrmL3NoHDCP480p30fpsHqCenc: [
      'drml3NoHdcp_h264_480p_hq_30fps_cenc.mp4', 44132909, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '480p',
        'quality': 'HQ',
      }
    ],
    DrmL3NoHDCP720p30fpsCenc: [
      'drml3NoHdcp_h264_720p_30fps_cenc.mp4', 28788524, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '720p',
      }
    ],
    DrmL3NoHDCP720p30fpsMqCenc: [
      'drml3NoHdcp_h264_720p_mq_30fps_cenc.mp4', 44199586, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '720p',
        'quality': 'MQ',
      }
    ],
    DrmL3NoHDCP720p30fpsHqCenc: [
      'drml3NoHdcp_h264_720p_hq_30fps_cenc.mp4', 73591730, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '720p',
        'quality': 'HQ',
      }
    ],
    DrmL3NoHDCP720p60fpsCenc: [
      'drml3NoHdcp_h264_720p_60fps_cenc.mp4', 38436183, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 60,
        'resolution': '720p',
      }
    ],
    DrmL3NoHDCP720p60fpsMqCenc: [
      'drml3NoHdcp_h264_720p_mq_60fps_cenc.mp4', 61027135, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 60,
        'resolution': '720p',
        'quality': 'MQ',
      }
    ],
    DrmL3NoHDCP1080p30fpsCenc: [
      'drml3NoHdcp_h264_1080p_30fps_cenc.mp4', 55005156, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '1080p',
      }
    ],
    DrmL3NoHDCP1080p30fpsMqCenc: [
      'drml3NoHdcp_h264_1080p_mq_30fps_cenc.mp4', 73580599, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '1080p',
        'quality': 'MQ',
      }
    ],
    DrmL3NoHDCP1080p30fpsHqCenc: [
      'drml3NoHdcp_h264_1080p_hq_30fps_cenc.mp4', 102970523, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 30,
        'resolution': '1080p',
        'quality': 'HQ',
      }
    ],
    DrmL3NoHDCP1080p60fpsCenc: [
      'drml3NoHdcp_h264_1080p_60fps_cenc.mp4', 72603681, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 60,
        'resolution': '1080p',
      }
    ],
    DrmL3NoHDCP1080p60fpsMqCenc: [
      'drml3NoHdcp_h264_1080p_mq_60fps_cenc.mp4', 95823710, 101.899, {
        'video_id': WIDEVINE_L3NOHDCP_VIDEO_ID,
        'widevine_signature': WIDEVINE_L3NOHDCP_SIGNATURE,
        'fps': 60,
        'resolution': '1080p',
        'quality': 'MQ',
      }
    ],
    ProgressiveLow: [
      'car_20130125_18.mp4', 15477531, 181.55,
      {'mimeType': 'video/mp4; codecs="avc1.42c01e"', 'resolution': '360p'}
    ],
    FrameGap: [
      'nq-frames24-tfdt23.mp4', 11883895, 242.46,
      {'mimeType': 'video/mp4; codecs="avc1.4d401e"', 'resolution': '360p'}
    ],
    FrameOverlap: [
      'nq-frames23-tfdt24.mp4', 11883895, 242.46,
      {'mimeType': 'video/mp4; codecs="avc1.4d401e"', 'resolution': '360p'}
    ],
    Webgl144p15fps: [
      'big-buck-bunny-h264-144p-15fps.mp4', 8620045, 634.60, {
        'mimeType': 'video/mp4; codecs="avc1.42c00c"',
        'fps': 15,
        'resolution': '144p'
      }
    ],
    Webgl240p30fps: [
      'big-buck-bunny-h264-240p-30fps.mp4', 19406299, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.4d4015"',
        'fps': 30,
        'resolution': '240p'
      }
    ],
    Webgl360p30fps: [
      'big-buck-bunny-h264-360p-30fps.mp4', 28791964, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.4d401e"',
        'fps': 30,
        'resolution': '360p'
      }
    ],
    Webgl480p30fps: [
      'big-buck-bunny-h264-480p-30fps.mp4', 56238435, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'fps': 30,
        'resolution': '480p'
      }
    ],
    Webgl720p30fps: [
      'big-buck-bunny-h264-720p-30fps.mp4', 106822776, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'fps': 30,
        'resolution': '720p'
      }
    ],
    Webgl720p60fps: [
      'big-buck-bunny-h264-720p-60fps.mp4', 181505335, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.4d4020"',
        'fps': 60,
        'resolution': '720p'
      }
    ],
    Webgl1080p30fps: [
      'big-buck-bunny-h264-1080p-30fps.mp4', 189028629, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.640028"',
        'fps': 30,
        'resolution': '1080p'
      }
    ],
    Webgl1080p60fps: [
      'big-buck-bunny-h264-1080p-60fps.mp4', 313230764, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.64002a"',
        'fps': 60,
        'resolution': '1080p'
      }
    ],
    Webgl1080p240fps: [
      'bbb_h264_240.mp4', 313230764, 30, {
        'mimeType': 'video/mp4; codecs="avc1.64002a"',
        'fps': 90,
        'resolution': '1080p'
      }
    ],
    Webgl1440p30fps: [
      'big-buck-bunny-h264-1440p-30fps.mp4', 454390604, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.640032"',
        'fps': 30,
        'resolution': '1440p'
      }
    ],
    Webgl2160p30fps: [
      'big-buck-bunny-h264-2160p-30fps.mp4', 873983617, 634.57, {
        'mimeType': 'video/mp4; codecs="avc1.640033"',
        'fps': 30,
        'resolution': '2160p'
      }
    ],
    Spherical144s30fps: [
      'spherical_h264_144s_30fps.mp4', 902503, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.4d400c"',
        'fps': 30,
        'resolution': '144p',
        'spherical': true
      }
    ],
    Spherical240s30fps: [
      'spherical_h264_240s_30fps.mp4', 2095800, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.4d4015"',
        'fps': 30,
        'resolution': '240p',
        'spherical': true
      }
    ],
    Spherical360s30fps: [
      'spherical_h264_360s_30fps.mp4', 3344623, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.4d401e"',
        'fps': 30,
        'resolution': '360p',
        'spherical': true
      }
    ],
    Spherical480s30fps: [
      'spherical_h264_480s_30fps.mp4', 7238157, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'fps': 30,
        'resolution': '480p',
        'spherical': true
      }
    ],
    Spherical720s30fps: [
      'spherical_h264_720s_30fps.mp4', 15323211, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.4d401f"',
        'fps': 30,
        'resolution': '720p',
        'spherical': true
      }
    ],
    Spherical720s60fps: [
      'spherical_h264_720s_60fps.mp4', 31284601, 149.29, {
        'mimeType': 'video/mp4; codecs="avc1.4d4020"',
        'fps': 60,
        'resolution': '720p',
        'spherical': true
      }
    ],
    Spherical1080s30fps: [
      'spherical_h264_1080s_30fps.mp4', 46455958, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.640028"',
        'fps': 30,
        'resolution': '1080p',
        'spherical': true
      }
    ],
    Spherical1080s60fps: [
      'spherical_h264_1080s_60fps.mp4', 59213840, 149.29, {
        'mimeType': 'video/mp4; codecs="avc1.64002a"',
        'fps': 60,
        'resolution': '1080p',
        'spherical': true
      }
    ],
    Spherical1440s30fps: [
      'spherical_h264_1440s_30fps.mp4', 97687330, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.640032"',
        'fps': 30,
        'resolution': '1440p',
        'spherical': true
      }
    ],
    Spherical1440s60fps: [
      'spherical_h264_1440s_60fps.mp4', 131898628, 149.29, {
        'mimeType': 'video/mp4; codecs="avc1.640033"',
        'fps': 60,
        'resolution': '1440p',
        'spherical': true
      }
    ],
    Spherical2160s30fps: [
      'spherical_h264_2160s_30fps.mp4', 179943784, 149.31, {
        'mimeType': 'video/mp4; codecs="avc1.640033"',
        'fps': 30,
        'resolution': '2160p',
        'spherical': true
      }
    ],
    Spherical2160s60fps: [
      'spherical_h264_2160s_60fps.mp4', 239610178, 149.29, {
        'mimeType': 'video/mp4; codecs="avc1.640033"',
        'fps': 60,
        'resolution': '2160p',
        'spherical': true
      }
    ],
  },
};

window.H264_STREAMS = H264_STREAMS;
})();

try {
  exports.H264_STREAMS = window.H264_STREAMS;
} catch (e) {
  // do nothing, this function is not supposed to work for browser, but it's for
  // Node js to generate json file instead.
}
