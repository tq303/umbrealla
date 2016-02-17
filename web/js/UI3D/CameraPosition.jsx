import React from 'react';

require('../../styles/ui-3d.scss');

class CameraPosition extends React.Component {
    constructor( props ) {
        super( props );

        this.interval = null;
        this.intervalSpeed = 50;
        this.cameraRotationX = 0;
        this.cameraRotationY = 0;

        this.state = {
            angleX: 0,
            angleY: 0,
            cameraZoom: this.props.canvas.cameraZoom
        };
    }
    repeatAction( action ) {
        this.interval = window.setInterval(action, this.intervalSpeed );
    }
    destroyAction() {
        window.clearInterval( this.interval );
    }
    moveCameraUp() {
        this.props.canvas.moveCameraUpDwn( this.cameraRotationY++ );
        this.setState({ angleY: this.cameraRotationY });
    }
    moveCameraDown() {
        this.props.canvas.moveCameraUpDwn( this.cameraRotationY-- );
        this.setState({ angleY: this.cameraRotationY });
    }
    moveCameraLeft() {
        this.props.canvas.moveCameraLeftRight( this.cameraRotationX++ );
        this.setState({ angleX: this.cameraRotationX });
    }
    moveCameraRight() {
        this.props.canvas.moveCameraLeftRight( this.cameraRotationX-- );
        this.setState({ angleX: this.cameraRotationX });
    }
    setCameraZoom(e) {
        this.props.canvas.setCameraZoom(e.target.value);
        this.setState({ cameraZoom: this.props.canvas.cameraZoom });
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
                <div>
                    <p>X: { this.state.angleX }</p>
                    <p>Y: { this.state.angleY }</p>
                    <p>Z: <input type="number" value={ this.state.cameraZoom } onChange={ this.setCameraZoom.bind(this) } /></p>
                </div>
            </div>
        )
    }
}

CameraPosition.propTypes = {
    canvas: React.PropTypes.object.isRequired
};

export default CameraPosition;
