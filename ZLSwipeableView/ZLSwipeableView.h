//
//  ZLSwipeableView.h
//  ZLSwipeableViewDemo
//
//  Created by Zhixuan Lai on 11/1/14.
//  Copyright (c) 2014 Zhixuan Lai. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ZLSwipeableView;

/// Delegate
@protocol ZLSwipeableViewDelegate <NSObject>

- (void)swipeableView:(ZLSwipeableView *)swipeableView
         didSwipeLeft:(UIView *)view;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
        didSwipeRight:(UIView *)view;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
          didPullDown:(UIView *)view;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
           didCollide:(UICollisionBehavior *)collisionBehavior;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
        didCancelSwipe:(UIView *)view;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
    didStartSwipingView:(UIView *)view
             atLocation:(CGPoint)location;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
          swipingView:(UIView *)view
           atLocation:(CGPoint)location
          translation:(CGPoint)translation;

- (void)swipeableView:(ZLSwipeableView *)swipeableView
    didEndSwipingView:(UIView *)view
           atLocation:(CGPoint)location;

@end

// DataSource
@protocol ZLSwipeableViewDataSource <NSObject>

@required
- (UIView *)nextViewForSwipeableView:(ZLSwipeableView *)swipeableView;

@end

@interface ZLSwipeableView : UIView

///
@property (nonatomic, weak) IBOutlet id<ZLSwipeableViewDataSource> dataSource;

///
@property (nonatomic, weak) IBOutlet id<ZLSwipeableViewDelegate> delegate;

/// Enable this to rotate the views behind the top view. Default to `YES`.
@property (nonatomic) BOOL isRotationEnabled;

/// Magnitude of the rotation in degrees
@property (nonatomic) float rotationDegree;

/// Relative vertical offset of the center of rotation. From 0 to 1. Default to
/// 0.3.
@property (nonatomic) float rotationRelativeYOffsetFromCenter;

/// Magnitude in points per second.
@property (nonatomic) CGFloat escapeVelocityThreshold;

/// minimum Displacement before swipe is registered, default is zero
@property (nonatomic) CGFloat minimumDisplacementThreshold;

/// relative Displacement of view (with respect to the views size) - swiping past this will always trigger a swipe
@property (nonatomic) CGFloat relativeDisplacementThreshold;

/// Magnitude of velocity at which the swiped view will be animated.
@property (nonatomic) CGFloat pushVelocityMagnitude;

/// Center of swipable Views. This property is animated.
@property (nonatomic) CGPoint swipeableViewsCenter;

/// Swiped views will be destroyed when they collide with this rect.
@property (nonatomic) CGRect collisionRect;

/// Magnitude of rotation for swiping views manually
@property (nonatomic) CGFloat manualSwipeRotationRelativeYOffsetFromCenter;

/// Number of Pixels before crossing the pull down threshold
@property (nonatomic) CGFloat pullDownReleaseThreshold;

/// Degrees of Freedom allowed during pull down and release ^
@property (nonatomic) CGFloat pullDownDegreesOfFreedom;

/// Magnitude in points per second of automated swipe motion - defaults to escape velocity threshold
@property (nonatomic) CGFloat animatedSwipePushMagnitude;

/// Gesture Recognizer Delegate
@property (nonatomic) id<UIGestureRecognizerDelegate> gestureRecognizerDelegate;

/// Discard all swipeable views on the screen.
- (void)discardAllSwipeableViews;

/// Load up to 3 swipeable views.
- (void)loadNextSwipeableViewsIfNeeded;

/// Swipe top view to the left programmatically
- (void)swipeTopViewToLeft;

/// Swipe top view to the right programmatically
- (void)swipeTopViewToRight;

/// Check if current position is in the pull down and release angle
- (BOOL)isPullingDown:(CGPoint) translation;

@end

