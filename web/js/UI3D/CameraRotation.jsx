import React from 'react';

import Control from './Control';

class CameraRotation extends Control {
    constructor( props ) {
        super( props );
        this.axisY = .2;
        this.axisX = .2;
    }
    rotateCameraUp() {
        this.props.umbrella.rotateCameraUpDwn( this.axisY );
    }
    rotateCameraDown() {
        this.props.umbrella.rotateCameraUpDwn( -this.axisY );
    }
    rotateCameraLeft() {
        this.props.umbrella.rotateCameraLeftRight( this.axisX );
    }
    rotateCameraRight() {
        this.props.umbrella.rotateCameraLeftRight( -this.axisX );
    }
    render() {
        return (
            <div className="controls-rotation">
                <h4>Rotate</h4>
                <div>
                    <div className="lat"
                         onMouseDown={ this.repeatAction.bind( this, this.rotateCameraLeft.bind(this) ) }
                         onMouseUp={ this.destroyAction.bind(this) }>
                     </div>
                    <div className="long">
                        <div onMouseDown={ this.repeatAction.bind( this, this.rotateCameraUp.bind(this) ) }
                             onMouseUp={ this.destroyAction.bind(this) }>
                        </div>
                        <div onMouseDown={ this.repeatAction.bind( this, this.rotateCameraDown.bind(this) ) }
                             onMouseUp={ this.destroyAction.bind(this) }>
                        </div>
                    </div>
                    <div className="lat"
                         onMouseDown={ this.repeatAction.bind( this, this.rotateCameraRight.bind(this) ) }
                         onMouseUp={ this.destroyAction.bind(this) }>
                     </div>
                </div>
            </div>
        )
    }
}

export default CameraRotation;
