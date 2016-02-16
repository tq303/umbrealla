import React from 'react';

require('../../styles/ui-3d.scss');

class CameraPosition extends React.Component {
    constructor( props ) {
        super( props );
        this.interval = null;
        this.intervalSpeed = 50;
        this.state = {
            angleX: 0,
            angleY: 0
        };
    }
    repeatAction( action ) {
        this.interval = window.setInterval(action, this.intervalSpeed );
    }
    destroyAction() {
        window.clearInterval( this.interval );
    }
    moveCameraUp() {
        this.props.umbrella.moveCameraUpDwn( 1 );
        this.setState({ angleY: this.props.umbrella.cameraRotationY });
    }
    moveCameraDown() {
        this.props.umbrella.moveCameraUpDwn( -1 );
        this.setState({ angleY: this.props.umbrella.cameraRotationY });
    }
    moveCameraLeft() {
        this.props.umbrella.moveCameraLeftRight( 1 );
        this.setState({ angleX: this.props.umbrella.cameraRotationX });
    }
    moveCameraRight() {
        this.props.umbrella.moveCameraLeftRight( -1 );
        this.setState({ angleX: this.props.umbrella.cameraRotationX });
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
                <label className="badge">X: { this.state.angleX }</label>
                <label className="badge">Y: { this.state.angleY }</label>
            </div>
        )
    }
}

CameraPosition.propTypes = {
    umbrella: React.PropTypes.object.isRequired
};

export default CameraPosition;
