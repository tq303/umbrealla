import React from 'react';

import Control from './Control';

class CameraPosition extends Control {
    constructor( props ) {
        super( props );
        this.axisY = 10;
        this.axisX = 10;
    }
    moveCameraUp() {
        this.props.umbrella.moveCameraUpDwn( this.axisY );
    }
    moveCameraDown() {
        this.props.umbrella.moveCameraUpDwn( -this.axisY );
    }
    moveCameraLeft() {
        this.props.umbrella.moveCameraLeftRight( this.axisX );
    }
    moveCameraRight() {
        this.props.umbrella.moveCameraLeftRight( -this.axisX );
    }
    render() {
        return (
            <div className="controls-direction">
                <h4>Move</h4>
                <div>
                    <div className="lat"
                         onMouseDown={ this.repeatAction.bind( this, this.moveCameraLeft.bind(this) ) }
                         onMouseUp={ this.destroyAction.bind(this) }>
                     </div>
                    <div className="long">
                        <div onMouseDown={ this.repeatAction.bind( this, this.moveCameraUp.bind(this) ) }
                             onMouseUp={ this.destroyAction.bind(this) }>
                        </div>
                        <div onMouseDown={ this.repeatAction.bind( this, this.moveCameraDown.bind(this) ) }
                             onMouseUp={ this.destroyAction.bind(this) }>
                        </div>
                    </div>
                    <div className="lat"
                         onMouseDown={ this.repeatAction.bind( this, this.moveCameraRight.bind(this) ) }
                         onMouseUp={ this.destroyAction.bind(this) }>
                     </div>
                </div>
            </div>
        )
    }
}

export default CameraPosition;
