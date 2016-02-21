import React from 'react';
import ReactDOM   from 'react-dom';

import UIAnimation from './UIAnimation';

class Animator {

    constructor( umbrellas ) {

        this.frames    = [];
        this.umbrellas = umbrellas;

        ReactDOM.render(<UIAnimation frames={ this.frames }/>, document.getElementById('ui-animation'));
    }

}

export default Animator;
