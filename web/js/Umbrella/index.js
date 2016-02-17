import THREE from 'three';

class Umbrella extends THREE.Object3D {
    constructor( ledCount, stripCount ) {
        super()

        // setup variables
        this.ledCount      = ledCount;
        this.stripCount    = stripCount;
        this.umbrellaCount = 1;
        this.ledDistance   = 1;

        // material & geometry
        this.material = {
            mesh: new THREE.MeshLambertMaterial( {color: 0xffffff, overdraw: 0.5} ),
            line: new THREE.LineBasicMaterial({ color: 0x0000ff })
        };

        this.create();
    }
    simpleObject() {
        return {
            lights: [],
            arms:   []
        };
    }
    create() {
        let umbrella = this.simpleObject();

        for (let i = 0; i < this.stripCount; i++) {

            umbrella.arms[i]   = this.createArms( (360 / this.stripCount) * i );
            umbrella.lights[i] = this.createLights( (360 / this.stripCount) * i );

        }

        return umbrella;
    }
    createArms( angle ) {

        let arm = new THREE.Geometry(),
            x   = Math.cos(this.radians(angle)),
            y   = Math.sin(this.radians(angle)),
            arms;

        // loop each led and place in x,y,z axis
        for (let i = 0; i < this.ledCount; i++) {

            let _x     = x * ( this.ledDistance * i ),
                _y     = y * ( this.ledDistance * i ),
                _angle = (( 90 / this.ledCount ) * i ) + 45,
                _z     = Math.cos(this.radians(_angle)) * ( this.ledDistance * i );

            arm.vertices.push(new THREE.Vector3(_x, _y, _z));
        }

        arms = new THREE.Line( arm, this.material.line );

        this.add( arms );

        return arms;
    }
    createLights( angle ) {

        let x      = Math.cos(this.radians(angle)),
            y      = Math.sin(this.radians(angle)),
            lights = {
                sphere: [],
                point:  []
            },
            geometry = new THREE.SphereGeometry( .5, 8 , 1 );

        // loop each led and place in x,y,z axis
        for (let i = 0; i < this.ledCount; i++) {

            let _x     = x * ( this.ledDistance * i ),
                _y     = y * ( this.ledDistance * i ),
                _angle = (( 90 / this.ledCount ) * i ) + 45,
                _z     = Math.cos(this.radians(_angle)) * ( this.ledDistance * i );

            lights.point[i] = new THREE.PointLight( 0xff0000, 1, 100 );
            lights.point[i].position.set( _x, _y, _z );

            this.add( lights.point[i] );

            lights.sphere[i] = new THREE.Mesh( geometry, this.material.mesh );
            lights.sphere[i].position.set( _x, _y, _z );

            this.add( lights.sphere[i] );
        }

        return lights;
    }
    radians( degrees ) {
        return degrees * (Math.PI / 180);
    }
}

export default Umbrella;
