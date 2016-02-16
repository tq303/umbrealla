import React from 'react';

require('../../styles/ui-3d.scss');

class Control extends React.Component {
    constructor( props ) {
        super( props );
        this.interval = null;
        this.intervalSpeed = 250;
    }
    repeatAction( action ) {
        this.interval = window.setInterval(action, this.intervalSpeed );
    }
    destroyAction() {
        window.clearInterval( this.interval );
    }
}

Control.propTypes = {
    umbrella: React.PropTypes.object.isRequired
};

export default Control;
