<?php

/**
 * @file
 * Definition of Drupal\views\Tests\Handler\AreaTextTest.
 */

namespace Drupal\views\Tests\Handler;

use Drupal\views\Tests\ViewUnitTestBase;

/**
 * Tests the text area handler.
 *
 * @see Drupal\views\Plugin\views\area\Text
 */
class AreaTextTest extends ViewUnitTestBase {

  /**
   * Views used by this test.
   *
   * @var array
   */
  public static $testViews = array('test_view');

  public static function getInfo() {
    return array(
      'name' => 'Area: Text',
      'description' => 'Test the core views_handler_area_text handler.',
      'group' => 'Views Handlers',
    );
  }

  protected function setUp() {
    parent::setUp();

    $this->enableModules(array('system'));
    $this->enableModules(array('filter'));
  }

  public function testAreaText() {
    $view = views_get_view('test_view');
    $view->setDisplay();

    // add a text header
    $string = $this->randomName();
    $view->displayHandlers['default']->overrideOption('header', array(
      'area' => array(
        'id' => 'area',
        'table' => 'views',
        'field' => 'area',
        'content' => $string,
      ),
    ));

    // Execute the view.
    $this->executeView($view);

    $view->display_handler->handlers['header']['area']->options['format'] = $this->randomString();
    $this->assertEqual(NULL, $view->display_handler->handlers['header']['area']->render(), 'Non existant format should return nothing');

    $view->display_handler->handlers['header']['area']->options['format'] = filter_default_format();
    $this->assertEqual(check_markup($string), $view->display_handler->handlers['header']['area']->render(), 'Existant format should return something');

    // Empty results, and it shouldn't be displayed .
    $this->assertEqual('', $view->display_handler->handlers['header']['area']->render(TRUE), 'No result should lead to no header');
    // Empty results, and it should be displayed.
    $view->display_handler->handlers['header']['area']->options['empty'] = TRUE;
    $this->assertEqual(check_markup($string), $view->display_handler->handlers['header']['area']->render(TRUE), 'No result, but empty enabled lead to a full header');
  }

}
