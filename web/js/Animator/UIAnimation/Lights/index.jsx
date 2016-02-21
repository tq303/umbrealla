import React from 'react';

import Light from './Light';

class Lights extends React.Component {

    constructor( params ) {
        super( params );

        // assign <Light/> to this.lights array
        this.lights = [];

        for (let i = 0; i < window.STRIP_COUNT; i++ ) {
            this.lights[i] = <Light/>;
        }

    }

    activateAll() {
        this.lights.forEach(( react )=> {
            react.type.prototype.setColour( '#337ab7' ).bind( react );
        });
    }

    deActivateAll() {
        this.lights.forEach(( react )=> {
            react.type.prototype.setColour( '#000000' ).bind( react );
        });
    }

    deActivateAll() {

    }

    render() {
        return (
            <div id="ui-lights">

                <div className="lights">
                    <p>{ this.lights[0] }</p>
                    <p>{ this.lights[7] }{ this.lights[1] }</p>
                    <p>{ this.lights[6] }{ this.lights[2] }</p>
                    <p>{ this.lights[5] }{ this.lights[3] }</p>
                    <p>{ this.lights[4] }</p>
                </div>

                <div className="controls">
                    <button onClick={ this.activateAll.bind(this) }><i className="fa fa-sun-o"></i></button>
                    <button onClick={ this.deActivateAll.bind(this) }><i className="fa fa-circle-thin"></i></button>
                </div>

            </div>
        )
    }
}

export default Lights;
