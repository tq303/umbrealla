import React from 'react';

class ActionRepeat extends React.Component {
    constructor( props ) {
        super( props );
        this.interval = null;
        this.intervalSpeed = 100;
    }
    repeatAction( action ) {
        this.interval = window.setInterval(action, this.intervalSpeed );
    }
    destroyAction() {
        window.clearInterval( this.interval );
    }
}

export default ActionRepeat;
