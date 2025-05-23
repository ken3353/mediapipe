// Copyright 2024 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>
#import "mediapipe/tasks/ios/components/containers/sources/MPPEmbeddingResult.h"
#import "mediapipe/tasks/ios/core/sources/MPPTaskResult.h"

NS_ASSUME_NONNULL_BEGIN

/** Represents the embedding results generated by `AudioEmbedder`. **/
NS_SWIFT_NAME(AudioEmbedderResult)
@interface MPPAudioEmbedderResult : MPPTaskResult

/**
 * An array of timestamped `EmbeddingResult` objects, each containing one set of results per
 * embedder head. In the "audio stream" mode, the array only contains one element, representing the
 * embedding result of the audio block that starts at EmbeddingResult.timestampInMilliseconds in the
 * audio stream. Otherwise, in the "audio clips" mode, the list may include multiple
 * `EmbeddingResult` objects, each classifying an interval of the entire audio clip that starts at
 * `EmbeddingResult.timestampInMilliseconds`.
 */
@property(nonatomic, readonly) NSArray<MPPEmbeddingResult *> *embeddingResults;

/**
 * Initializes a new `AudioEmbedderResult` with the given array of `MPPEmbeddingResult` and
 * timestamp (in milliseconds).
 *
 * @param embeddingResults The array of `EmbeddingResult` objects each containing one set of results
 * per embedder head.
 * @param timestampInMilliseconds The timestamp (in millisecondss) for this result.
 *
 * @return An instance of `AudioEmbedderResult` initialized with the given array of
 * `EmbeddingResult` objects and timestamp (in milliseconds).
 */
- (instancetype)initWithEmbeddingResults:(NSArray<MPPEmbeddingResult *> *)embeddingResults
                 timestampInMilliseconds:(NSInteger)timestampInMilliseconds;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
