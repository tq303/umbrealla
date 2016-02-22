import React from 'react';

import Light from './Light';

class Lights extends React.Component {

    constructor( params ) {
        super( params );

        // assign <Light/> to this.lights array
        let lights = [];

        for (let i = 0; i < window.STRIP_COUNT; i++) {
            lights[i] = null;
        }

        this.state = {
            lights: lights,
            integerColour: 0
        };
    }

    activateAll() {
        this.setState(( state )=> {
            return {
                lights: state.lights.map(()=> 'red')
            };
        });
    }

    deActivateAll() {
        this.setState(( state )=> {
            return {
                lights: state.lights.map(()=> null)
            };
        });
    }

    increaseColour() {
        if (this.state.integerColour <= 0) {
            this.setState({
                integerColour: 0
            })
        } else {
            this.setState({
                integerColour: this.state.integerColour - 1
            })
        }
    }
    decreaseColour() {
        if (this.state.integerColour >= 254) {
            this.setState({
                integerColour: 254
            })
        } else {
            this.setState({
                integerColour: this.state.integerColour + 1
            })
        }
    }

    render() {
        return (
            <div id="ui-lights">

                <div className="lights">
                    <p><Light colour={ this.state.lights[0] }/></p>
                    <p><Light colour={ this.state.lights[7] }/><Light colour={ this.state.lights[1] }/></p>
                    <p><Light colour={ this.state.lights[6] }/><Light colour={ this.state.lights[2] }/></p>
                    <p><Light colour={ this.state.lights[5] }/><Light colour={ this.state.lights[3] }/></p>
                    <p><Light colour={ this.state.lights[4] }/></p>
                </div>

                <div className="controls">
                    <button onClick={ this.activateAll.bind(this) }><i className="fa fa-sun-o"></i></button>
                    <button onClick={ this.deActivateAll.bind(this) }><i className="fa fa-circle-thin"></i></button>
                </div>
                <div className="set-colour">
                    <input value={ this.state.integerColour } type="number" />
                    <span onClick={ this.decreaseColour.bind(this) }><i className="fa fa-arrow-up"></i></span>
                    <span onClick={ this.increaseColour.bind(this) }><i className="fa fa-arrow-down"></i></span>
                </div>

            </div>
        )
    }
}

export default Lights;
