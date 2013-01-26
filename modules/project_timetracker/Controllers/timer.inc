<?php
class Timer
{
        private $_params;
        
        public function __construct($params)
        {
                $this->_params = $params;
        }
        

        
        public function readAction()
        {
                //read all the todo items while passing the username and password to authenticate
                $timer_items = TimeHandlers::getAllTimeItems($this->_params['uid'], $this->_params['task']);
                
                //return the list
                return $timer_items;
        }
        

} 
