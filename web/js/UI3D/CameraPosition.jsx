import React from 'react';

import Control from './Control';

class CameraPosition extends Control {
    constructor( props ) {
        super( props );
        this.longAmount = 2;
        this.lateralAmount = 2;
    }
    moveCameraUp() {
        this.props.umbrella.moveCameraUpDwn( this.longAmount );
    }
    moveCameraDown() {
        this.props.umbrella.moveCameraUpDwn( -this.longAmount );
    }
    moveCameraLeft() {
        this.props.umbrella.moveCameraLeftRight( this.lateralAmount );
    }
    moveCameraRight() {
        this.props.umbrella.moveCameraLeftRight( -this.lateralAmount );
    }
    render() {
        return (
            <div className="direction-controls">
                <div className="lat"
                     onMouseDown={ this.repeatAction.bind( this, this.moveCameraLeft.bind(this) ) }
                     onMouseUp={ this.destroyAction.bind(this) }>
                 </div>
                <div className="long">
                    <div onMouseDown={ this.moveCameraUp.bind( this, this.moveCameraUp.bind(this) ) }
                         onMouseUp={ this.destroyAction.bind(this) }>
                    </div>
                    <div onMouseDown={ this.moveCameraDown.bind( this, this.moveCameraDown.bind(this) ) }
                         onMouseUp={ this.destroyAction.bind(this) }>
                    </div>
                </div>
                <div className="lat"
                     onMouseDown={ this.repeatAction.bind( this, this.moveCameraRight.bind(this) ) }
                     onMouseUp={ this.destroyAction.bind(this) }>
                 </div>
            </div>
        )
    }
}

export default CameraPosition;
