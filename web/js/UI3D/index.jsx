import React from 'react';

import ActionRepeat from './ActionRepeat';

require('../../styles/ui-3d.scss');

class UI3D extends ActionRepeat {
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
                     onMouseDown={ this.repeatAction( this.moveCameraLeft.bind(this) ) }
                     onMouseUp={ this.destroyAction.bind(this) }>
                 </div>
                <div className="long">
                    <div onMouseDown={ this.moveCameraUp.bind(this) }>
                    </div>
                    <div onMouseDown={ this.moveCameraDown.bind(this) }>
                    </div>
                </div>
                <div className="lat"
                     onMouseDown={ this.repeatAction( this.moveCameraRight.bind(this) ) }
                     onMouseUp={ this.destroyAction.bind(this) }>
                 </div>
            </div>
        )
    }
}

UI3D.propTypes = {
    umbrella: React.PropTypes.object.isRequired
};

export default UI3D;
