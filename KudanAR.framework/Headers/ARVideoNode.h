#import <Foundation/Foundation.h>
#import <KudanAR/ARMeshNode.h>

@class ARVideoTexture;
@class VuforiaTrackableImage;
@class ARVideoTextureMaterial;

/**
 An ARVideoNode is a subclass of ARNode that is used to render video content.
 */
@interface ARVideoNode : ARMeshNode

/**
 The video texture associated with the node.
 */
@property (nonatomic) ARVideoTexture *videoTexture;

/**
 The material of this video node, which is typically an instance of ARVideoTextureMaterial.
 
 This provides convenient access to this node's material without need for a cast.
 */
@property (nonatomic) ARVideoTextureMaterial *videoTextureMaterial;

/**
 Initialise an ARVideoNode using a video texture. This is useful for when your video and audio are in separate files.
 
 Example of use:
 @code
 ARVideoTexture *videoTexture = [[ARVideoTexture alloc] initWithVideoFile:@"video.mp4" audioFile:"audio.aac"];
 ARVideoNode *videoNode = [[ARVideoNode alloc] initWithVideoTexture:videoTexture];
 @endcode
 
 @param videoTexture The video texture to initialise with.
 */
- (instancetype)initWithVideoTexture:(ARVideoTexture *)videoTexture;

/**
 Initialise with a file in the app bundle. This is the simplest and easiest way to load a video file that has audio into a video node.
 
 Example of use:
 @code
 ARVideoNode *videoNode = [[ARVideoNode alloc] initWithBundledFile:@"example.mp4"];
 @endcode
 
 @param file The file in the app bundle to initialise with. The file path is relative to the app bundle and includes the file extension.
 */
- (instancetype)initWithBundledFile:(NSString *)file;

/**
 Starts/resumes playback from the saved time. If no time is currently saved, starts from the beginning. Default playback state is paused.
 
 Example of use:
 @code
 [videoNode play];
 @endcode
 */
- (void)play;

/**
 Pauses playback. Current video time will be saved.
 
 Example of use:
 @code
 [videoNode pause];
 @endcode
 */
- (void)pause;

/**
 Reset the video's position to 0 and its state to paused.
 
 Example of use:
 @code
 [videoNode reset];
 @endcode
 */
- (void)reset;

@end
